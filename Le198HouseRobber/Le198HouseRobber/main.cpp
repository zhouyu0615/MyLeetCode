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
		DpSum[1] = max(nums[0],nums[1]);
		for (int i = 2; i < len; i++)
		{
			DpSum[i] = max(DpSum[i-2]+nums[i],DpSum[i-1]);
		}
		return DpSum[len-1];
	}
private:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{




	getchar();
	return 0;
}