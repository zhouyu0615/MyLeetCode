#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {		  
		   row = matrix.size();
		   col = matrix[0].size();

		   int maxIndex = row*col - 1;
		   
		   int low = 0;
		   int high = maxIndex;
		   int mid = (low + high) / 2;

		   while (low<=high)
		   {
			   int temp = getMatNum(mid, matrix);
			   if (target==temp)
			   {
				   return true;
			   }
			   else if (temp < target)
			   {
				   low = mid + 1;
			   }
			   else
			   {
				   high = mid - 1;
			   }
			   mid = (high + low) / 2;
		   }
		   return false;
	}


private:
	int row=0;
	int col = 0;
	//把矩阵转为一维数组//
	int getMatNum(int index, vector<vector<int>>& matrix)
	{
		int i = (int)index / col;
		int j = (int)index % col;

		return matrix[i][j];
	}
};



int main()
{
	Solution testCase;

	vector<vector<int>> matrix = { {1,2,3},{5,6,8} };

	cout << testCase.searchMatrix(matrix, 8);



	getchar();
	return 0;
}


