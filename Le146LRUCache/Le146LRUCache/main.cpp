#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


struct DLinkNode{
	int key;
	int value;
	DLinkNode *prev;
	DLinkNode *next;
	DLinkNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL){}
};

DLinkNode *head = NULL, *tail = NULL;


//把节点添加到链表头部//
void addNodeInHead(DLinkNode* node)
{
	node->next = head->next;
	node->prev = head;

	head->next->prev = node;
	head->next = node;
}


void removeNode(DLinkNode* node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;

}

//把节点移到链表头部//
void updateNode(DLinkNode* node)
{
	removeNode(node);
	addNodeInHead(node);
}

//删除并返回链表尾部的节点//
DLinkNode* popTailNode()
{
	DLinkNode* removeNode = tail->prev;

	removeNode->prev->next = tail;
	tail->prev = removeNode->prev;
	
	
	return removeNode;
}


class LRUCache{
public:
	int capacity=0,NodeCount=0;
	unordered_map<int, DLinkNode*> map;
	//head,tail为辅助节点//


	LRUCache(int capacity) {
		this->capacity = capacity;

		head = new DLinkNode(-1, -1);
		tail = new DLinkNode(-1, -1);
		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		tail->next = NULL;

		this->NodeCount = 0;
	}

	int get(int key) {
		if (map.count(key)>0)
		{
			DLinkNode* Node = map[key];
			updateNode(Node);
		    return Node->value;
		}
		else
		{
			return -1;
		}

	}

	void set(int key, int value) {
		DLinkNode* node=NULL;
		if (map.count(key)==0) 
		{
			node = new DLinkNode(key, value);
			if (this->capacity==NodeCount)//已满
			{
				DLinkNode *p = popTailNode();
				map.erase(p->key);
				delete p;
				addNodeInHead(node);
			}
			else
			{			
				addNodeInHead(node);
				NodeCount++;
			}
		}
		else   //缓存中已存在//
		{
			node = map[key];
			node->value = value;
			updateNode(node);
		}
		map[key] = node;
	}
};


int main()
{
	LRUCache test(2);

	test.set(2, 1);
	test.set(1, 1);


	cout << "Result= " << test.get(2);
	//cout << "Result= " << test.get(2);
	test.set(4, 1);
	cout << "Result= " << test.get(1);
	cout << "Result= " << test.get(2);
	//cout << "Result= " << test.get(4);


	getchar();
	return 0;
}