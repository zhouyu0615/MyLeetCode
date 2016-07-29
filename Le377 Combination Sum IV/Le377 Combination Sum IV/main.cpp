#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution1 {
public:
	int combinationSum4(vector<int>& nums, int target) 
	{
		
		if (nums.size()==0||target==0)
		{
			return 0;
		}		
		sort(nums.begin(), nums.end());
		Dfs(nums, target);
		return count;
	}
public:
	void Dfs(vector<int>&nums, int target)
	{
		if (target==0)
		{
			count++;
			return;
		}
		for (int i = 0; i < nums.size()&&nums[i]<=target;i++)
		{
			target = target - nums[i];
			Dfs(nums, target);
			target = target + nums[i];
		}
	}

private:
	int count = 0;
};


class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {

		vector<int> DpCounts;
		DpCounts.assign(target + 1, 0);
		DpCounts[0] = 1;

		for (int i = 0; i <= target;i++)
		{
			for (int j = 0; j < nums.size();j++)
			{
				if (i>=nums[j])
				{
					DpCounts[i] = DpCounts[i] + DpCounts[i - nums[j]];
				}
			}
		}
		return DpCounts[target];
	}

};



int main()
{
	vector<int> nums= {1, 2, 3};

	Solution testCase;
	cout << testCase.combinationSum4(nums, 4) << endl;

	getchar();
	return 0;
}