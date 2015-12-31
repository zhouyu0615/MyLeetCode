#include <iostream>

using namespace std;

class Solution {

public:
	int uniquePaths(int m, int n) {
		//int **pathDp;
		//pathDp = (int **)malloc(sizeof(int *) * m);
		//for (int i = 0; i < m; i++)
		//	pathDp[i] = (int *)malloc(sizeof(int) * n);

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

int main()
{
	Solution testCase;
	cout << testCase.uniquePaths(3, 7)<<endl;

	getchar();
	return 0;
}