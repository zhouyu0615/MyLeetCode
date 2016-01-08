#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int row = board.size();
		if (row == 0) return;
		int col = board[0].size();
		queue<int> OFlagQueue;

		vector<vector<bool>> visited;
		visited.assign(row, vector<bool> (col,false));
		vector<int> visitedPoints;

		vector <vector<int>> directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (board[i][j] =='O'&&!visited[i][j])
				{
					bool surround = true;
					OFlagQueue.push(i*col + j);
					visited[i][j] = true;

					visitedPoints.clear();

					while (!OFlagQueue.empty())
					{
						int point = OFlagQueue.front();
						OFlagQueue.pop();
						visitedPoints.push_back(point);
						int x = point / col;
						int y = point%col;
						
						for (int k = 0; k < directions.size();k++)
						{
							int nextX = x + directions[k][0];
							int nextY = y + directions[k][1];

							if (nextX>=0&&nextX<row&&nextY>=0&nextY<col)
							{
								if (board[nextX][nextY] == 'O'&&!visited[nextX][nextY])
								{
									OFlagQueue.push(nextX*col + nextY);
									visited[nextX][nextY] = true;
								}
							}
							else
							{
								surround = false;
							}
						}
					}
					//被包围的‘O’点//
					if (surround==true)
					{
						for (int i = 0; i < visitedPoints.size();i++)
						{
							int p = visitedPoints[i];
							board[p / col][p%col] = 'X';
						}
					}
				}
			}
		}

	}
};





class Solution2 {

private:
	int row=0;
	int col = 0;
public:
	void solve(vector<vector<char>>& board) {


		row = board.size();
		if (row==0)
		{
			return;
		}
		col = board[0].size();

		for (int i = 0; i < row;i++) 
		{
			Bfs(board, i, 0);
			Bfs(board, i, col-1);
		}

		for (int j = 0; j < col;j++)
		{
			Bfs(board, 0, j);
			Bfs(board, row - 1, j);
		}


		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (board[i][j]=='V')
				{
					board[i][j] = 'O';
				}
				else
				{
					board[i][j] = 'X';
				}
			}
		}

	}

	void Bfs(vector<vector<char>>& board,int x, int y)
	{
		if (board[x][y] != 'O') return;

		queue<int> OFlagQueue;
		OFlagQueue.push(x*col+y);

		board[x][y] = 'V';

		vector <vector<int>> directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

		while (!OFlagQueue.empty())
		{
			int  Point = OFlagQueue.front();
			OFlagQueue.pop();

			int x = Point / col;
			int y = Point%col;
			
			for (int k = 0; k < directions.size();k++)
			{
				int nextX = x + directions[k][0];
				int nextY = y + directions[k][1];

				if (nextX >= 0 && nextX < row&&nextY >= 0&&nextY<col)
				{
					if (board[nextX][nextY]=='O')
					{
						OFlagQueue.push(nextX*col + nextY);
						board[nextX][nextY] = 'V';
					}
				}

			}

		}

	}
};


int main()
{
	Solution2 testCase;

	vector < vector<char>> board= {{'X', 'X', 'X', 'X'}, { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' }, { 'X', 'O', 'X', 'X' }};

	vector<vector<char>>::iterator pI;
	vector<char>::iterator   pI2;

	testCase.solve(board);

	for (pI = board.begin(); pI != board.end();++pI)
	{
		for (pI2 = pI->begin(); pI2 != pI->end();++pI2)
		{
			cout << *pI2 << " ";
		}
		cout << endl;
	}




	getchar();
	return 0;
}