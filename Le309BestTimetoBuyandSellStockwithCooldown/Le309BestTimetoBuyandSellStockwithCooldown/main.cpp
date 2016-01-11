#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1) return 0;

		vector<int> sell;//第i天不持有股票所获得的最大累计收益//
		vector<int> buy; //第i天持有股票所获得的最大累计收益//

		sell.assign(len, 0);
		buy.assign(len, 0);

		sell[1] = Max(0, prices[1] - prices[0]);

		buy[0] = -prices[0];
		buy[1] = Max(-prices[0], -prices[1]);

		for (int i = 2; i < len;i++)
		{
			sell[i] = Max(sell[i - 1], buy[i - 1] + prices[i]);
			buy[i] = Max(buy[i - 1], sell[i - 2] - prices[i]);
		}

		return sell[len - 1];
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

	vector<int> prices = {1,2,3,0,2};
	cout << testCase.maxProfit(prices)<<endl;


	getchar();
	return 0;
}