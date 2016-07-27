#include <iostream>
#include <vector>
#include <queue>

using  namespace std;



class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> IndexQue;

		if (k==0||nums.size()==0)
		{
			return result;
		}

		for (int i = 0; i < k;i++)
		{
			while (!IndexQue.empty()&&nums[i]>nums[IndexQue.back()])
			{
				IndexQue.pop_back();
			}
			IndexQue.push_back(i);
		}
		for (int i = k; i < nums.size();i++)
		{
			result.push_back(nums[IndexQue.front()]);
			while (!IndexQue.empty()&&nums[i]>=nums[IndexQue.back()])
			{
				IndexQue.pop_back();
			}
			if (!IndexQue.empty()&&(i-IndexQue.front())>=k)
			{
				IndexQue.pop_front();
			}
			IndexQue.push_back(i);
		}
		result.push_back(nums[IndexQue.front()]);

		return result;
	}
};


int main()
{

	getchar();
	return 0;
}