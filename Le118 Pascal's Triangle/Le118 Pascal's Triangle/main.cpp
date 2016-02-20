#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector<int> RowTemp;		
		vector<vector<int>> result;

		for (int i = 1; i <= numRows;i++)
		{
			RowTemp.push_back(1);
			if (i <= 2)
			{
				result.push_back(RowTemp);
			}
			else
			{
				int halfLen = i / 2;
				for (int j = 1; j < halfLen; j++)
				{
					RowTemp[j] = result[i - 2][j - 1] + result[i - 2][j];
					RowTemp[i - j-1] = RowTemp[j];
				}

				if (i%2==1)
				{
					RowTemp[halfLen] = result[i - 2][halfLen-1] + result[i - 2][halfLen];
				}
				result.push_back(RowTemp);
			}
		}
		return result;
	}
};



int main()
{

	vector<vector<int>> result;

	Solution testCase;

	result=testCase.generate(10);

	for (int i = 0; i < result.size();i++)
	{
		for (int j = 0; j < result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}


	getchar();
	return 0;
}


