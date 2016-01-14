#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return;

		
		int NonZeroCount = 0;
		for (int i = 0; i<len;i++)
		{		
			if (nums[i]!=0)
			{
				nums[NonZeroCount] = nums[i];
				NonZeroCount++;
			}
		}

		for (int i = NonZeroCount; i < len;i++)
		{
			nums[i] = 0;
		}
	}
};


int main()
{
	vector<int> nums = { 0, 1, 2, 3, 0, 4, 0, 0, 5, 6, 0, 0 };
	Solution testCase;

	testCase.moveZeroes(nums);

	for each (int i in nums)
	{
		cout << i << " ";
	}


	getchar();
	return 0;
}

