#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size()==0)
		{
			return INT_MIN;
		}
		int sum = nums[0];
		int max = nums[0];
		
		for (int i = 1; i < nums.size();i++)
		{			
			if (sum<0)
			{
				sum = nums[i];
			}
			else
			{
				sum = sum + nums[i];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
		return max;

	} 
};






int main()
{

	Solution testCase;
	vector<int> nums = {-2,1};

	cout << testCase.maxSubArray(nums)<<endl;

	getchar();
	return 0;
}