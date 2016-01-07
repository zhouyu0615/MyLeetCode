#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();

		if (len == 0) return 0;
		if (len == 1) return nums[0];

		vector<int> DpSum;
		DpSum.assign(len, 0);

		DpSum[0] = nums[0];
		DpSum[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len-1; i++)
		{
			DpSum[i] = max(DpSum[i - 2] + nums[i], DpSum[i - 1]);
		}

		int max1 = DpSum[len - 2]; //从第一家到倒数第二家能获得的最大数目//

		DpSum[0] = 0;
		DpSum[1] = nums[1];
		for (int i = 2; i < len;i++) //从第二家到最后一家获得最大数目//
		{
			DpSum[i] = max(DpSum[i - 2] + nums[i], DpSum[i - 1]);
		}

		int max2 = DpSum[len - 1];

		return max(max1, max2);
	}
private:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};



int main()
{
	vector<int> nums = { 2, 1, 1, 1, 3, 4, 5 };

	Solution testCase;
	cout << testCase.rob(nums)<<endl;


	getchar();
	return 0;
}