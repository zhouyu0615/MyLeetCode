#include <iostream>
#include <vector>



using namespace std;


class Solution {
public:
	int jump(vector<int>& nums) {
		int jumps = 0;
		int curRch = 0;//进行jumps次后所能达到的最大位置//
		int curMax = 0;//当前所能到达的最大位置//

		int len = nums.size();

		for (int i = 0; i < len;i++)
		{
			if (curRch<i)
			{
				jumps++;
				curRch = curMax;
			}
			curMax = Max(curMax,i+nums[i]);
		}
		return jumps;
	}
private:
	inline int Max(int a, int b)
	{
		return a>b ? a : b;
	}
};



int main()
{

	vector<int> nums = { 2, 3, 1, 1, 4 };
	Solution testCase;

	cout << testCase.jump(nums) << endl;

	getchar();
	return 0;
}