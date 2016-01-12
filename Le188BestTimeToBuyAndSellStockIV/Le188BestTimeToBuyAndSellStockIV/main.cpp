#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {

		int len = prices.size();
		if (k==0||len<=1)
		{
			return 0;
		}

		if (k>=(len/2))
		{
			int result = 0;
			for (int i = 1; i < len;i++)
			{
				if (prices[i]-prices[i-1]>0)
				{
					result += prices[i] - prices[i - 1];
				}
			}
			return result;
		}
	
		vector<vector<int>> gProfit; //gProfit[i][j]到达i次交易第j天,所能获取最大的收益//
		vector<vector<int>> lProfit;  //lProfit[i][j]到达i次交易第j天卖出，所能获取的最大收益//

		gProfit.assign(k+1, vector<int>(len, 0)); 
		lProfit.assign(k+1, vector<int>(len, 0));
		

		for (int i = 1; i <= k;i++)
		{
			for (int j = 1; j < len;j++)
			{
				lProfit[i][j] = Max(lProfit[i][j - 1] + prices[j] - prices[j - 1],
					gProfit[i - 1][j - 1] + Max(0, prices[j] - prices[j - 1]));
				gProfit[i][j] = Max(gProfit[i][j - 1], lProfit[i][j]);
			}
		}


		return gProfit[k][len - 1];
	}
private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{
	Solution testCase;
	vector<int> Prices = { 2, 3, 1, 3, 4, 6 ,5};

	cout << testCase.maxProfit(5,Prices) << endl;

	getchar();
	return 0;
}