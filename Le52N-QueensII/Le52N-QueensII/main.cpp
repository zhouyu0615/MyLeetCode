#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {

private:
	int  Count=0;
	vector<int> QueenPos; //queenPos[i]=j;��ʾ��i���ϻʺ�λ��j����
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
		if (row == N) //��������N��ʱ
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

	//true--safe; ���Ե�ROW��COL�з��ûʺ��Ƿ�ȫ//
	bool isSafe(int row, int col)
	{
		//�в����ظ�
		for (int i = 0; i < row; i++)
		{
			if (col == QueenPos[i])
			{
				return false;
			}
		}


		for (int i = (row - 1); i >= 0; i--)
		{
			//��Խ��߲����ظ�
			if (QueenPos[i] == (col - (row - i)))
			{
				return false;
			}

			//�ҶԽ����ϲ����ظ�
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

	cout << "����" << res << "�ⷨ" << endl;

	getchar();
	return 0;
}
