#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
private:
	vector<vector<int>> result;
	vector<int> source;
	vector<bool> flag; //标记是否加入tmp
	int length = 0;

	void Dfs(int startPos, vector<int>&tmp)
	{
		if (startPos==length)
		{
			result.push_back(tmp);
			return;
		}
		else
		{
			for (int i = 0; i < length;i++)
			{
				if (flag[i])
				{
					continue;
				}
				if (i>0)
				{
					if (source[i] == source[i - 1] && (!flag[i - 1]))
					{
						continue;
					}	
				}
				flag[i] = true;
				tmp.push_back(source[i]);
				Dfs(startPos + 1, tmp);
				tmp.pop_back();
				flag[i] = false;
			}
			return;
		}

	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

		length = nums.size();
		if (length == 0)
		{
			return result;
		}

		sort(nums.begin(), nums.end());

		source = nums;

		flag.assign(length, false);
		vector<int> tmp;;
		Dfs(0, tmp);

		return result;
	}
};









class Solution1 {
private:
	vector<vector<int>> result;
	vector<int> source;
	int length = 0;

	void swap(int &i, int &j)
	{
		int tmp = i;
		i = j;
		j = tmp;
		return;
	}

	bool IsSwap(int cur, int index,vector<int> &nums)
	{
		int i = cur;
		while (nums[i]!=nums[index]&&i<index)
		{
			i++;
		}
		if (i==index)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}


	void Dfs(int startPos, vector<int>& nums)
	{
		if (startPos==length)
		{
			result.push_back(nums);
			return;
		}
		else
		{
			for (int i = startPos; i < length;i++)
			{
				if (!IsSwap(startPos,i,nums))
				{
					continue;
				}
				swap(nums[startPos], nums[i]);
				Dfs(startPos + 1, nums);
				swap(nums[startPos], nums[i]);
			}
		}
	
	
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

		length = nums.size();
		if (length == 0)
		{
			return result;
		}

		//sort(nums.begin(), nums.end());
		Dfs(0, nums);
	
		return result;
	}
};





int main()
{
	Solution1 test;
	vector<int> nums = { 1, 2, 2,1};


	vector<vector<int>>::iterator pIter;
	vector<int>::iterator pI;
	vector<vector<int>> result;
	result = test.permuteUnique(nums);


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