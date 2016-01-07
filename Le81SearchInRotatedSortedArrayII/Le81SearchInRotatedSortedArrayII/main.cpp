#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	bool search(vector<int>& nums, int target) {

		int left = 0;
		int right = nums.size() - 1;

		int mid = 0;
		while (left<=right)
		{
			mid = (left + right) >> 1;
			if (nums[mid]==target||nums[left]==target||nums[right]==target)
			{
				return true;
			}

			if ((nums[mid]==nums[left])&&(nums[mid]==nums[right]))
			{
				left++;
				right--;
			}
			else if (nums[left]<=nums[mid])
			{
				if (nums[left]<=target&&target<nums[mid])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if (nums[mid] < target&&target <=nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}

		return false;
	}
};


class Solution2 {
public:
	bool search(vector<int>& nums, int target) {

		for (int i = 0; i < nums.size();i++)
		{
			if (target==nums[i])
			{
				return true;
			}
		}
		return false;
	}
};


int main()
{
	vector<int> nums{ 5, 5, 6, 7, 8, 1, 2, 3, 3,  5 };
	Solution testCase;

	cout << testCase.search(nums, 4);



	getchar();
	return 0;
}
