#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {

		int len = nums.size();
		if (len<=1)
		{
			return len;
		}
		vector<int> Dp; //DP[i]为到nums[i]数字为末尾的递增序列长度//
		Dp.assign(len, 1);

		for (int i = 1; i < len;++i)
		{			
			for (int j = 0; j < i;++j)
			{
				if (nums[i]>nums[j])
				{
					Dp[i] = Max(Dp[i], Dp[j] + 1);
				}
			}
		}

		int result = 0;
		for (int i = 0; i < len;i++)
		{
			result = Max(result, Dp[i]);
		}

		return result;
	}

private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{

	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18, 1, 9 };

	Solution testCase;

	cout << testCase.lengthOfLIS(nums) << endl;

	getchar();
	return 0;
}