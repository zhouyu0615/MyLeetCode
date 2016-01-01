#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> DPMinSum(row, vector<int>(col, 0));

		for (int i = 0; i < row;i++)
        {
			for (int j = 0; j < col;j++)
			{
				if (i == 0 && j == 0)
				{
					DPMinSum[i][j] = grid[i][j];
					continue;
				}
				if ((i == 0) && (j != 0)) //第一行
				{
					DPMinSum[i][j] = DPMinSum[i][j - 1]+grid[i][j];
				}
				else if ((j == 0) && (i != 0))//第一列
				{
					DPMinSum[i][j] = DPMinSum[i - 1][j]+grid[i][j];
				}
				else
				{
					DPMinSum[i][j] = Min(DPMinSum[i - 1][j], DPMinSum[i][j - 1]) + grid[i][j];
				}
			}
        }

		return DPMinSum[row - 1][col - 1];
	}
private:
	int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};


int main()
{
	Solution testCase;

	vector <vector<int >> grid= {{1, 5}, { 3, 6 }};

	cout << testCase.minPathSum(grid);

	getchar();
	return 0;
}