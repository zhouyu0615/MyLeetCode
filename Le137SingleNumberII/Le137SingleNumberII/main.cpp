#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int bitsum[32] = { 0 };
		int result=0;
		for (int i = 0; i < 32;i++)
		{
			for (int j = 0; j < nums.size();j++)
			{
				bitsum[i] += (nums[j]>>i)&1;
			}
			result = result | ((bitsum[i] % 3)<<i);
		}

		return result;
	}
};




int main()
{
	Solution testCase;

	vector<int> nums = {1,2,3,4,1,2,3,1,2,3};

	cout<<testCase.singleNumber(nums);


	getchar();
	return 0;
}
