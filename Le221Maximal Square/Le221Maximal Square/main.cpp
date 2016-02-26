#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0) return 0;

		int col = matrix[0].size();

		int result = 0;

		vector<vector<int>> maxDp; //maxDp[i][j]表示到i,j位置所成正方形的边长//
		maxDp.assign(row, vector<int>(col, 0));

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (matrix[i][j] == '1')
				{
					maxDp[i][j] = 1;

					if (i >= 1 && j >= 1)
					{
						maxDp[i][j] = Min(maxDp[i - 1][j - 1], Min(maxDp[i][j - 1], maxDp[i - 1][j])) + 1;
					}
				}
				result = Max(result, maxDp[i][j]);
			}
		}
		return result*result;
	}
private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	};

	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	};
};


int main()
{
	vector<vector<char>> matrix = { "00","00" };

	Solution testCase;
	cout << testCase.maximalSquare(matrix) << endl;

	getchar();
	return 0;
}