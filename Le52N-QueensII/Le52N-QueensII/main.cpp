#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {

private:
	int  Count=0;
	vector<int> QueenPos; //queenPos[i]=j;表示第i行上皇后位于j列上
	int N = 0;

public:
	int totalNQueens(int n) {
		N = n;
		QueenPos.assign(N, 0);

		DfsFind(0, 0);

		return Count;
	}

private:
	void DfsFind(int row, int col)
	{
		if (row == N) //搜索到第N行时
		{
			Count++;
			return;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (isSafe(row, i))
				{
					QueenPos[row] = i;
					DfsFind(row + 1, 0);
					QueenPos[row] = 0;
				}
			}

		}

	}

	//true--safe; 测试第ROW行COL列放置皇后是否安全//
	bool isSafe(int row, int col)
	{
		//列不能重复
		for (int i = 0; i < row; i++)
		{
			if (col == QueenPos[i])
			{
				return false;
			}
		}


		for (int i = (row - 1); i >= 0; i--)
		{
			//左对角线不能重复
			if (QueenPos[i] == (col - (row - i)))
			{
				return false;
			}

			//右对角线上不能重复
			if (QueenPos[i] == (col + (row - i)))
			{
				return false;
			}
		}
		return true;
	}

};


int main()
{
	Solution testCase;
	
	int res = testCase.totalNQueens(9);

	cout << "共有" << res << "解法" << endl;

	getchar();
	return 0;
}
