#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		

		size = nums.size();
		sort(nums.begin(), nums.end());

		DfsAdd(0, nums);

		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> temp;
	int size = 0;

	
	void DfsAdd(int start, vector<int>& nums)
	{
		if (temp.size()<=size)
		{
			result.push_back(temp);
		}

		for (int i = start; i < size;i++)
		{
			if ((i!=start)&&nums[i]==nums[i-1])
			{
				continue;
			}
			temp.push_back(nums[i]);
			DfsAdd(i + 1, nums);
			temp.pop_back();
		}	
	}
};

int main()
{



	getchar();
	return 0;
}
