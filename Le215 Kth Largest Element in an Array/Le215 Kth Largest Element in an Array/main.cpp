#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int,vector<int>,greater<int>> priQueue;

		int len = nums.size();
		for (int i = 0; i < len;++i)
		{
			priQueue.push(nums[i]);
			if (priQueue.size()>k)
			{
				priQueue.pop();
			}
		}
		return priQueue.top();
	}
};

int main()
{

	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	Solution testCase;
	cout<<testCase.findKthLargest(nums, 2)<<endl;
	getchar();
	return 0;
}