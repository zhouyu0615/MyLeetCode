#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:

	vector<vector<int>> result;
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int len = nums.size();

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (i>0 && nums[i] == nums[i - 1])//去除重复的值//
			{
				continue;
			}

			find(nums, i + 1, len - 1, nums[i]);

		}
		return result;
	}

	void find(vector<int> &nums, int start, int end, int target)
	{
		vector<int> temp(3,0);
		while (start < end)
		{
			int sum = nums[start] + nums[end] + target;
			if (sum == 0)
			{
				temp[0]=target;
				temp[1]=nums[start];
				temp[2]=nums[end];
				result.push_back(temp);
				while (start < end&&nums[start] == nums[start + 1]) //跳过重复的值//
				{
					start++;
				}
				while (start < end&&nums[end] == nums[end - 1])//跳过重复的值//
				{
					end--;
				}
				start++;
				end--;
			}
			else if (sum < 0)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}
};




int main()
{
	Solution test;
	vector<int> nums = { -10, 5, -11, -15, 7, -7, -10, -8, -3, 13, 9, -14, 4, 3, 5, -7, 13, 1, -4, -11, 5, 9, -11, -4, 14, 0, 3, -10, -3, -7, 10, -5, 13, 14, -5, 6, 14, 0, 5, -12, -10, -1, -11, 9, 9, 1, -13, 0, -13, -1, 4, 0, -7, 8, 3, 14, -15, -9, -10, -3, 0, -15, -1, -2, 6, 9, 11, 6, -14, 1, 1, -9, -14, 6, 7, 10, 14, 2, -13, -13, 8, 6, -6, 8, -9, 12, 7, -9, -11, 4, -4, -4, 4, 10, 1, -12, -3, -2, 1, -10, 6, -13, -3, -1, 0, 11, -5, 0, -2, -11, -6, -9, 11, 3, 14, -13, 0, 7, -14, -4, -4, -11, -1, 8, 6, 8, 3 };

	vector<vector<int>>::iterator pIter;
	vector<int>::iterator pI;
	vector<vector<int>> result;
	result = test.threeSum(nums);



	for (pIter = result.begin(); pIter != result.end(); ++pIter)
	{
		for (pI = pIter->begin(); pI != pIter->end(); ++pI)
		{
			cout << *pI << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}

