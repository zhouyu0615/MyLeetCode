#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int len = nums.size();

		if (len==0)
		{
			return INT_MIN;
		}
		
		int localMax = nums[0];//乘了当前数，所能达到的最大值//
		int localMin = nums[0];

		int gMax=nums[0];

		for (int i = 1; i < len;i++)
		{   
			int localMaxCopy = localMax;
			localMax = Max(nums[i], Max(localMaxCopy*nums[i], localMin*nums[i]));
			localMin = Min(nums[i], Min(localMaxCopy*nums[i], localMin*nums[i]));

			gMax = Max(gMax, localMax);
		}

		return gMax;
	}

private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};

int main()
{

	Solution testCase;

	vector<int> Nums = { 2, 3, -2, -2 };

	cout << testCase.maxProduct(Nums) << endl;

	getchar();
	return 0;
}
