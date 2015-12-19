#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size();

		int limit = n / 2;


		
		for (int i = 0; i < limit;i++)
		{
			for (int j = i; j < n-1-i;j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][i];
				matrix[n - 1 - j][i] = matrix[n-1-i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[n-1-(n-1-j)][n - 1 - i];
				matrix[n - 1 - (n - 1 - j)][n - 1 - i] = tmp;
			}
		}
		return;
		
	}
};



void rotate(int** matrix, int matrixRowSize, int matrixColSize) {

	int n = matrixRowSize;

	int limit = n / 2;

	for (int i = 0; i < limit; i++)
	{
		for (int j = i; j < n - 1 - i; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - (n - 1 - j)][n - 1 - i];
			matrix[n - 1 - (n - 1 - j)][n - 1 - i] = tmp;
		}
	}
	return;
}



int main()
{
	vector<vector<int>> matrix = { { 1, 2 }, { 3, 4 } };

	Solution testCase;
	testCase.rotate(matrix);

	vector<vector<int>>::iterator pIter;
	vector<int>::iterator pI;

	

	for (pIter = matrix.begin(); pIter != matrix.end(); ++pIter)
	{
		for (pI = pIter->begin(); pI != pIter->end(); ++pI)
		{
			cout << *pI << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}


