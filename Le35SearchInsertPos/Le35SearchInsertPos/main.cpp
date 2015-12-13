#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0;
		int high = nums.size()-1;
		int mid = (low + high) / 2;
		while (low<=high)
		{
			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[mid]<target)
			{
				low = mid+1;	
			}
		   else
			{
				high = mid-1;
			}
			mid = (high-low) / 2+low;
		}

		return mid;
	}
};



int main()
{
	Solution testCase;
	vector<int> nums = { 1, 3,4};

	cout << testCase.searchInsert(nums, 2)<<endl;



	getchar();
	return 0;
}