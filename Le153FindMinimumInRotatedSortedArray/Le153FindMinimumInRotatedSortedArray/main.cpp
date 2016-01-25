#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();

		BinarySearch(nums, 0, len-1);

		return MinVal;
	}

private:
	int MinVal=INT_MAX;
	void BinarySearch(vector<int>& nums, int left, int right)
	{
		if (left>=right)
		{
			MinVal = Min(MinVal, nums[left]);
			return;
		}
		if (nums[left]<nums[right])
		{
			MinVal = Min(MinVal, nums[left]);
			return;
		}
		int mid = (left + right) / 2;
		
		if (nums[left]<nums[mid])//left到MID是递增的//
		{
			BinarySearch(nums,mid + 1, right);
		}
		else  //折点在left与Mid之间//
		{
			BinarySearch(nums, left+1, mid);
		}
	}

	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};


int main()
{


}