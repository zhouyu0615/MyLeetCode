#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> tmp;
		source = candidates;
		dfs(tmp, 0, target);
		return result;
	}
private:
	vector<vector<int>> result;
	vector<int> source;

	int sum(const vector<int>  &tmp)
	{
		int sum = 0;
		for (int i = 0; i < tmp.size();i++)
		{
			sum += tmp[i];
		}
		return sum;
	}

	void dfs(vector<int> &tmp,int startPos,int target)
	{
		if (startPos==source.size())
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
			for (int i = startPos; i < source.size();i++)
			{
				tmp.push_back(source[i]);
				dfs(tmp, i, target);
				tmp.pop_back();
			}
		}
	}

};



int main()
{







	getchar();
	return 0;
}


