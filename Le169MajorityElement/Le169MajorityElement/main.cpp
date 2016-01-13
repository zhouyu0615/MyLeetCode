#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {

		int count = 1;
		int MajNum = nums[0];
		int len = nums.size();

		for (int i = 1; i < len;i++)
		{
			if (nums[i]==MajNum)
			{
				count++;
			}
			else
			{
				count--;
			}

			if (count<=0)
			{
				MajNum = nums[i];
				count = 1;
			}
		}
		return MajNum;
	}
};



int main()
{

	vector<int> nums = { 1,2,3,1,1,2,1,2,1,1 };

	Solution testCase;

	cout << testCase.majorityElement(nums)<<endl;

	getchar();
	return 0;
}

