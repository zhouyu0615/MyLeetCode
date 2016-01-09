#include <iostream>
#include <vector>
#include <queue>



using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();

		vector<vector<bool>> VisitLandPoints;

		VisitLandPoints.assign(row, vector<bool>(col, false));

		queue<int> LandQueue;

		int IslandCount = 0;

		vector<vector<int>> directions = { { 1, 0 }, { -1, 0 }, {0,1},{0,-1} };

		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (grid[i][j] == '1'&&!VisitLandPoints[i][j])
				{
					LandQueue.push(i*col + j);
					VisitLandPoints[i][j] = true;
					while (!LandQueue.empty())
					{
						int point = LandQueue.front();
						LandQueue.pop();

						int x = point / col;
						int y = point%col;
						
						for (int k = 0; k < directions.size();k++)
						{
							int nextX = x + directions[k][0];
							int nextY = y + directions[k][1];

							if (nextX >= 0 && nextX < row&&nextY>=0&&nextY<col)
							{
								if (grid[nextX][nextY]=='1'&&!VisitLandPoints[nextX][nextY])
								{
									LandQueue.push(nextX*col + nextY);
									VisitLandPoints[nextX][nextY] = true;
								}
							}
						}
					}
					IslandCount++;
				}
			}
		}
		return IslandCount;
	}
};



int main()
{

	vector<vector<char>> grid = { { '1' } };

	Solution testCase;

	cout << testCase.numIslands(grid);

	getchar();
	return 0;
}