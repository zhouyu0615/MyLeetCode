#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		 m_Row = matrix.size();
		 if (m_Row == 0) return false;

		 m_Col = matrix[0].size();

		 if (target<matrix[0][0]||target>matrix[m_Row-1][m_Col-1])
		 {
			 return false;
		 }

		for (int i = 0; i < m_Row; i++)
		{
			if (target < matrix[i][0])
			{
				return false;
			}
			if (target>=matrix[i][0]||target<=matrix[i][m_Col-1])
			{
				if (BinarySearch(matrix,i,target))
				{
					return true;
				}
				else
				{
					continue;
				}
			}
		}
		return false;
	}

private:
	int m_Row=0;
	int m_Col=0;
	bool BinarySearch(vector<vector<int>>& matrix,int row,int target)
	{
		int high = m_Col - 1;
		int low = 0;
		int mid = (high + low) / 2;


		if (matrix[row][high] == target || matrix[row][low] == target || matrix[row][mid] == target)
		{
			return true;
		}

		while (low<=high)
		{
			if (matrix[row][mid]<target)
			{
				low = mid + 1;
			}else if (matrix[row][mid]>target)
			{
				high = mid - 1;
			}
			else
			{
				return true;
			}
			mid = (high + low) / 2;
		}
		return false;
	}

};


class Solution2 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) return false;

		int col = matrix[0].size();

		if (target<matrix[0][0] || target>matrix[row-1][col-1])
		{
			return false;
		}

		int i = 0; //行
		int j = col-1;//列
		int temp = 0;
		while (i<row&&j>=0)
		{
			temp = matrix[i][j];
			if (temp<target) //i行不会有target//
			{
				i++;
			}else if (temp>target) //j列不会有target//
			{
				j--;
			}
			else if (temp==target)
			{
				return true;
			}
		}
		return false;
	}
}; 





int main()
{


	getchar();
	return 0;
}
