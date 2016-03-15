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



class Solution2 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		
		 return find(0, nums.size() - 1,k, nums);


	}

private:
	int find(int left, int right,const int k,vector<int> &nums)
	{
		int temp = nums[left];
		int i = left;
		int j = right;
		while (i<j)
		{
			while (j>i&&nums[j]<=temp)
			{
				j--;
			}
			nums[i] = nums[j];
			while (i<j&&nums[i]>=temp)
			{
				i++;
			}
			nums[j] = nums[i];
		}
		nums[i] = temp;

		if (left<j&&k<=j) //这时如果右指针还大于等于k，说明kth在左半边
		{
			return find(left, j - 1, k, nums);;
		}

		if (i<right&&i<=k)//这时如果左指针小于等于K,说明kth在右半边
		{
			find(i + 1, right, k, nums);
		}
		return nums[k - 1];
	}
};



int main()
{

	vector<int> nums = { 3, 1,2};
	Solution testCase;
	cout<<testCase.findKthLargest(nums, 2)<<endl;
	getchar();
	return 0;
}