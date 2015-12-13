#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> tmp;
		
		for (int i = 0; i < candidates.size();i++)
		{
			candmap[candidates[i]]++;//key为数值，value为该数值的个数
		}

		for (map<int, int>::iterator it = candmap.begin(); it != candmap.end();++it)
		{
			for (int i = 0; i < it->second;i++)
			{
				tmp.push_back(it->first);
				Dfs(tmp, it, target);
			}
			for (int i = 0; i < it->second;i++)
			{
				tmp.pop_back();
			}
		}
		return result;
	}

private:
	vector<vector<int>> result;
	map<int, int> candmap;

	int sum(const vector<int>& tmp)
	{
		int sum=0;
		for (int i = 0; i < tmp.size();++i)
		{
			sum += tmp[i];
		}
		return sum;
	}

	void Dfs(vector<int>& tmp, map<int,int>::iterator it,int target)
	{
	      if (it==candmap.end())
	      {
			  return;
	      }
		  int tempSum = sum(tmp);
		  if (tempSum==target)
		  {
			  result.push_back(tmp);
			  return;
		  }else if (tempSum>target)
		  {
			  return;
		  }
		  else
		  {
			  for (++it; it != candmap.end(); ++it)
			  {
				  for (int i = 0; i < it->second;i++)
				  {
					  tmp.push_back(it->first);
					  Dfs(tmp, it, target);
				  }
				  for (int i = 0; i < it->second;i++)
				  {
					  tmp.pop_back();
				  }
			  }
		  }
	}
};




class Solution1 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		  sort(candidates.begin(), candidates.end());
		  vector<int> tmp;
	      
		  source = candidates;

		  Dfs(tmp, 0, target);
		
		  return result;
	}

private:
	vector<vector<int>> result;
	vector<int> source;

	void Dfs(vector<int> &tmp, int startPos, int target)
	{
		if (target==0)
		{
			result.push_back(tmp);
			return;
		}
		if (startPos>=source.size()||source[0]>target)
		{
			return;
		}
		for (int i = startPos; i < source.size();i++)
		{
			if (source[i]<=target)
			{
				tmp.push_back(source[i]);
				Dfs(tmp, i + 1, target - source[i]);
				tmp.pop_back();
				while ((i < (source.size()-1))&&(source[i]==source[i+1]))
				{
					i++;
				}
			}
		}
		
	}
};





int main()
{
	Solution1 testCase;
	vector<int> nums = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 2;


	vector<vector<int>>::iterator pIter;
	vector<int>::iterator pI;
	vector<vector<int>> result;
	result = testCase.combinationSum2(nums, target);



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