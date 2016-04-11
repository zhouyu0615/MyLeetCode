#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		long long allProduct = 1;

		vector<int> result ;
		int len = nums.size();

		result.assign(len, 0);

		int numsOf0 = 0;
		for (int i = 0; i < len;i++)
		{
			if (nums[i]!=0)
			{
				allProduct *= nums[i];
			}
			else
			{
				numsOf0++;
			}
		}

		for (int i = 0; i < nums.size();i++)
		{
			if (nums[i]!=0)
			{
				result[i] = (numsOf0==0?allProduct / nums[i]:0);
			}
			else
			{
				result[i] = (numsOf0 == 1 ? allProduct : 0);
			}
		}
		return result;
	}
};


class Solution2 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		vector<int> result;
		int len = nums.size();
		result.assign(len, 1);
		
		result[0] = 1;
		for (int i = 1; i < len;i++)
		{
			result[i] = result[i-1]*nums[i - 1];
		}

		int right = 1;
		for (int i = len - 1; i >= 0;i--)
		{
			result[i] = result[i] * right;
			right = right*nums[i];		
		}


		return result;
	}
};




int main()
{

	vector<int> nums = { 1, 2, 3, 4};


	Solution2 testCase;
	vector<int> result;
	result=testCase.productExceptSelf(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}


	getchar();
	return 0;
}