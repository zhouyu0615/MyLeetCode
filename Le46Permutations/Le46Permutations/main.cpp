#include <iostream>
#include <vector>


using namespace std;



class Solution {
private:
	vector<vector<int>> result;
	void swap(int &i, int &j)
	{
		int tmp = i;
		i = j;
		j = tmp;
		return;
	}

	void Dfs(int startPos,vector<int>&nums)
	{
		int len = nums.size();
		if (startPos==(len-1))
		{
			result.push_back(nums);
			return;
		}
		else
		{
			for (int i = startPos; i < len;i++)
			{
				swap(nums[startPos],nums[i]);
				Dfs(startPos+1, nums);
				swap(nums[startPos], nums[i]);
			}
		}	
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		
		if (nums.size()==0)
		{
			return result;
		}
		Dfs(0, nums);

		return result;
	}


};



int main()
{
	Solution test;
	vector<int> nums = { 1, 2, 3 };



	vector<vector<int>>::iterator pIter;
	vector<int>::iterator pI;
	vector<vector<int>> result;
	result = test.permute(nums);


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

