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


//�ѽڵ���ӵ�����ͷ��//
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

//�ѽڵ��Ƶ�����ͷ��//
void updateNode(DLinkNode* node)
{
	removeNode(node);
	addNodeInHead(node);
}

//ɾ������������β���Ľڵ�//
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
	//head,tailΪ�����ڵ�//


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
			if (this->capacity==NodeCount)//����
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
		else   //�������Ѵ���//
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