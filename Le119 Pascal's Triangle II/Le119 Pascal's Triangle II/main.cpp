#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		rowIndex++;
		vector<int> result;
		result.assign(rowIndex, 1);

		int halfLen = rowIndex / 2;
		for (int i = 1; i < halfLen;i++)
		{
			result[i] = numOfCombination(rowIndex-1,i);
			result[rowIndex - i-1] = result[i];
		}

		if (rowIndex%2==1)  //奇数列//
		{
			result[halfLen] = numOfCombination(rowIndex - 1, halfLen);
		}

		return result;
	}

private:
	//组合数，从n个数中选出m个//
	int numOfCombination(int n,int m)
	{
		if (n==m||m==0)
		{
			return 1;
		} 
		unsigned long long upNum = 1;
		for (int i = n; i > (n - m);i--)
		{
			upNum = upNum*i;
		}
		unsigned long long downNum = 1;
		for (int i = 1; i <= m;i++)
		{
			downNum = downNum*i;
		}

		return upNum / downNum;
	}
};



class Solution2 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result;

		result.assign(rowIndex+1, 1);

		for (int i = 2; i <= rowIndex;i++) //行
		{
			for (int j = i - 1; j > 0;j--)
			{
				result[j] = result[j] + result[j - 1];
			}
		}

		return result;
	}
};



int main()
{
	vector<int> result;
	
	Solution2 testCase;

	result=testCase.getRow(30);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << " ";
	}

	getchar();
	return 0;
}