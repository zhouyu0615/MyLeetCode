#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		size = nums.size();

		sort(nums.begin(), nums.end());

		Dfs(0,nums);
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> temp;
	int size = 0;

	void Dfs(int start, vector<int>& nums)
	{
		if (temp.size()<=size)
		{
			result.push_back(temp);
		}

		for (int i = start; i < size; i++)
		{
			temp.push_back(nums[i]);
			Dfs(i + 1,nums);
			temp.pop_back();
		}
	}

};


int main()
{
	Solution testCase;
	vector<vector<int>> res;
	vector<int> nums = { 1, 2, 3 };

	vector < vector<int> >::iterator pI;
	vector<int>::iterator pI2;

	res = testCase.subsets(nums);

	for (pI = res.begin(); pI != res.end(); ++pI)
	{
		for (pI2 = pI->begin(); pI2 != pI->end(); ++pI2)
		{
			cout << *pI2 << " ";
		}
		cout << endl;
	}



	getchar();
	return 0;
}

