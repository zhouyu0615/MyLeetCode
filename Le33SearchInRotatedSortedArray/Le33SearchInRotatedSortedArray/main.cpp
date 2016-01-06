#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size()==0)
		{
			return -1;
		}

		return BinarySearch(nums, 0, nums.size() - 1, target);

	}

private:
	int BinarySearch(vector<int>& nums, int left, int right, int target)
	{
		if (left>right)
		{
			return -1;
		}

		int mid = (left + right) / 2;
	    
		if (nums[left] == target) return left;
		if (nums[mid] == target) return mid;
		if (nums[right] == target) return right;


		if (nums[left]<nums[right]) 
		{
			if (target<nums[left]||target>nums[right])
			{
				return -1;
			}else if (target<nums[mid])
			{
				return BinarySearch(nums, left+1, mid - 1, target);
			}
			else
			{
				return BinarySearch(nums, mid + 1, right, target);
			}
		}

		if (nums[left]<nums[mid])
		{
			if (target>nums[left]&&target<nums[mid])
			{
				return BinarySearch(nums, left+1, mid - 1, target);
			}
			else
			{
				return BinarySearch(nums, mid + 1, right-1, target);
			}
		}
		else
		{
			if (target>nums[mid]&&target<nums[right])
			{
				return BinarySearch(nums, mid + 1, right-1, target);
			}
			else
			{
				return BinarySearch(nums, left + 1, mid - 1, target);
			}

		}
	}

};




int main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	
	Solution testCase;
	

	cout << testCase.search(nums, 6)<<endl;



	getchar();
	return 0;
}


