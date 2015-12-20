#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {

private:
	vector<vector<string>> result;
	vector<int> QueenPos; //queenPos[i]=j;表示第i行上皇后位于j列上
	vector<string> strQueenPos;
	int N = 0;

public:
	vector<vector<string>> solveNQueens(int n) {
		N = n;
		QueenPos.assign(N, 0);


		DfsFind(0, 0);

		return result;
	}

private:
	void DfsFind(int row,int col)
	{
		if (row==N) //搜索到第N行时
		{
			result.push_back(strQueenPos);
			return;
		}
		else
		{
			for (int i = 0; i < N;i++)
			{
				if (isSafe(row, i))
				{
					string tmp;
					tmp.assign(N, '.');
					tmp[i] = 'Q';
					QueenPos[row] = i;
					strQueenPos.push_back(tmp);
					DfsFind(row + 1, 0);
					QueenPos[row] = 0;
					strQueenPos.pop_back();
				}
			}

		}

	}

	//true--safe; 测试第ROW行COL列放置皇后是否安全//
	bool isSafe(int row, int col)
	{
		//列不能重复
		for (int i = 0; i < row;i++)
		{
			if (col==QueenPos[i])
			{
				return false;
			}
		}

		
		for (int i = (row-1); i >= 0;i--)
		{
			//左对角线不能重复
			if (QueenPos[i]==(col-(row-i)))
			{
				return false;
			}

			//右对角线上不能重复
			if (QueenPos[i]==(col+(row-i)))
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
	vector<vector<string>> res;
	res=testCase.solveNQueens(9);

	vector<vector<string>>::iterator pIter;
	vector<string>::iterator It;
 
	int count = 0;
	for (pIter = res.begin(); pIter != res.end();++pIter)
	{
		for (It = pIter->begin(); It != pIter->end();++It)
		{
			cout << *It << " "<<endl;
		}
		cout << endl;
		count++;
	}

	cout << "共有" << count << "解法" << endl;

	getchar();
	return 0;
}


