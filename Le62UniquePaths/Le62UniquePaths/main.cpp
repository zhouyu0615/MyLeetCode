#include <iostream>

using namespace std;

class Solution {

public:
	int uniquePaths(int m, int n) {

		m_row = m;
		m_col = n;
		Dfs(1, 1);

		return countResult;

	}
private:
	int m_row,m_col;
	int countResult=0;
	void Dfs(int row, int col)
	{
		if (row == m_row&&col==m_col)
		{
			countResult++;
			return;
		}
		if (row==m_row)
		{
			Dfs(row, col + 1);
			return;
		}
		else if (col==m_col)
		{
			Dfs(row + 1, col);
			return;
		}
		else
		{
			Dfs(row + 1, col);
			Dfs(row, col + 1);
			return;
		}
	}
};


class Solution2 {
public:
	int uniquePaths(int m, int n) {
		int ** dpPath = new int *[m];
		for (int i = 0; i < m; i++)
			dpPath[i] = new int[n];

		dpPath[0][0] = 1;


		for (int i = 0; i < m;i++)
		{
			for (int j = 0; j < n;j++)
			{
				if (i==0&&j==0)
				{
					continue;
				}
				if ((i==0)&&(j!=0))
				{
					dpPath[i][j] = dpPath[i][j-1];
				}else if ((j==0)&&(i!=0))
				{
					dpPath[i][j] = dpPath[i-1][j];
				}else 
				{
					dpPath[i][j] = dpPath[i-1][j] + dpPath[i][j-1];
				}
			}
		}

		int methods = dpPath[m - 1][n - 1];

		for (int i = 0; i < m; i++)
		{
			delete dpPath[i];
			dpPath[i] = NULL;
		}
		delete[]  dpPath;
		dpPath = NULL;

		return methods;
	}
};



int main()
{
	Solution2 testCase;
	cout << testCase.uniquePaths(12, 12)<<endl;

	getchar();
	return 0;
}