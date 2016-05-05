#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>

using namespace std;



class Node
{
public:
	int Key;
	int Count;
	Node(int key, int val) :Key(key), Count(val){};

	friend bool operator < (const  Node &n1, const  Node &n2);


};

inline bool operator <  (const  Node &n1, const  Node &n2)
{
	return n1.Count > n2.Count;
};


class Solution {

public:
	vector<int> topKFrequent(vector<int>& nums, int k) {

		priority_queue<Node> priQue;
		map<int, int> pollMap;

	
		for (int i = 0; i < nums.size();i++)
		{
			pollMap[nums[i]]++;
		}

		map<int, int>::iterator iter;
		for (iter = pollMap.begin(); iter != pollMap.end();iter++)
		{
			Node temp(iter->first, iter->second);
			if (priQue.size()<k)
			{			
				priQue.push(temp);
			}
			else
			{
				if (iter->second>priQue.top().Count)
				{
					priQue.pop();
					priQue.push(temp);
				}
			}
		}

		vector<int> result;
		while (!priQue.empty())
		{
			result.push_back(priQue.top().Key);
			priQue.pop();
		}

		reverse(result.begin(), result.end());
		return result;
	}
};


int main()
{

	vector<int> nums = { 1, 1, 1, 2, 2, 1, 3, 3, 3, 4 };

	Solution testCase;
	
	vector<int> result = testCase.topKFrequent(nums, 2);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}

	
	getchar();
	return 0;
}