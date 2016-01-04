#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		size = k;

		Dfs(1, n);
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> temp;
	int size;

	void Dfs(int start,int end)
	{
		if (temp.size()==size)
		{
			result.push_back(temp);
			return;
		}

		for (int i = start; i <=end;i++)
		{
			temp.push_back(i);
			Dfs(i+1, end);
			temp.pop_back();
		}
	}
};



int main()
{
	Solution testCase;
	vector<vector<int>> res;

	vector < vector<int> >::iterator pI;
	vector<int>::iterator pI2;

	res = testCase.combine(4, 2);

	for (pI = res.begin(); pI != res.end();++pI)
	{
		for (pI2 = pI->begin(); pI2 != pI->end();++pI2)
		{
			cout << *pI2<<" ";
		}
		cout << endl;
	}


	getchar();
	return 0;
}
