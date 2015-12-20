#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {

private:
	vector<vector<string>> result;
	vector<int> QueenPos; //queenPos[i]=j;��ʾ��i���ϻʺ�λ��j����
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
		if (row==N) //��������N��ʱ
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

	//true--safe; ���Ե�ROW��COL�з��ûʺ��Ƿ�ȫ//
	bool isSafe(int row, int col)
	{
		//�в����ظ�
		for (int i = 0; i < row;i++)
		{
			if (col==QueenPos[i])
			{
				return false;
			}
		}

		
		for (int i = (row-1); i >= 0;i--)
		{
			//��Խ��߲����ظ�
			if (QueenPos[i]==(col-(row-i)))
			{
				return false;
			}

			//�ҶԽ����ϲ����ظ�
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

	cout << "����" << count << "�ⷨ" << endl;

	getchar();
	return 0;
}


