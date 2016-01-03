#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		vector<int> rowFlag;
		vector<int> colFlag;
		int row = matrix.size();
		if (row==0)
		{
			return;
		}
		int col = matrix[0].size();
		rowFlag.assign(row, 0);
		colFlag.assign(col, 0);
		

		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (matrix[i][j]==0)
				{
					rowFlag[i] = 1;
					colFlag[j] = 1;				
				}
			}
		}

		for (int i = 0; i < row;i++)
		{
			if (rowFlag[i]==1)
			{
				setRowZero(i, matrix);
			}		
		}

		for (int i = 0; i < col; i++)
		{
			if (colFlag[i] == 1)
			{
				setColZero(i, matrix);
			}
		}

	}

private:
	void setRowZero(int row, vector<vector<int>>& matrix)
	{
		int len = matrix[0].size();

		for (int i = 0; i < len;i++)
		{
			matrix[row][i] = 0;
		}
	}

	void setColZero(int col, vector<vector<int>>& matrix)
	{
		int len = matrix.size();

		for (int i = 0; i < len; i++)
		{
			matrix[i][col] = 0;
		}
	}
};


int main()
{




	getchar();
	return 0;
}

