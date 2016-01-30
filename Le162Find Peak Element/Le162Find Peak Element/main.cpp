#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int len = nums.size();

		if (len<=1)
		{
			return 0;
		}

		for (int i = 0; i < (len-1);i++)
		{
			if (i==0)
			{
				if (nums[i]>INT_MIN&&nums[i]>nums[i+1])
				{
					return i;
				}
			}

			if (nums[i]>nums[i-1]&&nums[i]>nums[i+1])
			{
				return i;
			}
		}
		
		if (nums[len-1]>nums[len-2])
		{
			return (len - 1);
		}
	}
};



class Solution2 {
public:
	int findPeakElement(vector<int>& nums) {

		int left = 0;
		int right = nums.size() - 1;
		
		while (left<right)
		{
			int mid = (left + right) / 2;
			if (nums[mid]>nums[mid+1])
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};



int main()
{

	vector<int> nums = { 1, 2, 3, 1 };
	
	Solution2 testCase;
	cout << testCase.findPeakElement(nums)<<endl;



	getchar();
	return 0;
}