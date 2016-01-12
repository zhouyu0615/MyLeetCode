#include <iostream>
#include <vector>



using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();

		if (len<=1)
		{
			return 0;
		}
		vector<int> Profit1;
		vector<int> Profit2;

		Profit1.assign(len, 0); //1-i天能够获得的最大收益//
		Profit2.assign(len, 0); //i-n天能够获得的最大收益//

		int low = prices[0]; //低价买进//
		int profit = 0;
		for (int i = 1; i < len;i++)
		{
			if (low>prices[i])
			{
				low = prices[i];
			}
			else
			{
				if (prices[i]-low>profit)
				{
					profit = prices[i] - low;
				}
			}
			Profit1[i] = profit;
		}

		int high = prices[len - 1]; //高价出售//
		profit = 0;
		for (int i = len - 2; i >=0;i--)
		{
			if (high<prices[i])
			{
				high = prices[i];	
			}
			else
			{
				if (high-prices[i]>profit)
				{
					profit = high - prices[i];
				}			
			}
			Profit2[i] = profit;
		}

		int maxProfit = 0;
		for (int i = 0; i < len;i++)
		{
			int temp = Profit1[i] + Profit2[i];
			if (temp>maxProfit)
			{
				maxProfit = temp;
			}
		}
		return maxProfit;
	}
};



int main()
{
	vector<int> Prices = { 1, 2, 6, 2, 3, 4, 5, 6 };

	Solution testCase;

	cout << testCase.maxProfit(Prices) << endl;



	getchar();
	return 0;
}
