#include <iostream>
#include <vector>

using namespace  std;


class Solution {
public:
	int findMin(vector<int>& nums) {
		int minVal = nums[0];

		for (int i = 1; i < nums.size();i++)
		{
			if (minVal>nums[i])
			{
				minVal = nums[i];
			}
		}
		return minVal;
	}
};



class Solution {
public:
	int findMin(vector<int>& nums) {
		
		int len = nums.size();
		BinarySearch(nums, 0, len - 1);

		return MinVal;
	}
private:
	int MinVal = INT_MAX;
	void BinarySearch(vector<int>& nums, int left, int right)
	{
		while (nums[left]==nums[left+1]&&left<=right)
		{
			left++; 
		} //Ìø¹ýÖØ¸´ÔªËØ//

		while (nums[right]==nums[right-1]&&((right-1)>=left))
		{
			right--;
		}


		if (left>=right)
		{
			MinVal = Min(MinVal, nums[left]);
			return;
		}

		if (nums[left] < nums[right])
		{
			MinVal = Min(MinVal, nums[left]);
			return;
		}

		int mid = (left + right) / 2;

		if (nums[left]<nums[mid])
		{
			BinarySearch(nums, mid+1, right);
		}
		else
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

	getchar();
	return 0;
}