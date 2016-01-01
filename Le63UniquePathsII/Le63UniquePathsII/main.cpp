#include <iostream>
#include <vector>

using namespace std;







class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();


		int ** dpPath = new int *[m];
		for (int i = 0; i < m; i++)
			dpPath[i] = new int[n];

		if (obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)
		{
			return 0;
		}
		else
		{
			dpPath[0][0] = 1;
		}
		


		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}

				if (obstacleGrid[i][j]==1) //ÕÏ°­
				{
					dpPath[i][j] = 0;
					continue;
				}
				if ((i == 0) && (j != 0))
				{
					dpPath[i][j] = dpPath[i][j - 1];
				}
				else if ((j == 0) && (i != 0))
				{
					dpPath[i][j] = dpPath[i - 1][j];
				}
				else
				{
					dpPath[i][j] = dpPath[i - 1][j] + dpPath[i][j - 1];
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
	Solution testCase;
	vector<vector<int>> obstacleGrid = { { 0, 0 }, { 1, 0 } };
 
	cout << testCase.uniquePathsWithObstacles(obstacleGrid);


	getchar();
	return 0;
}