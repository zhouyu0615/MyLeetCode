#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0) return 0;
		
		int result = 0;

		for (int i = 1; i < len;i++)
		{
			if (prices[i]>prices[i-1])
			{
				result += prices[i] - prices[i - 1];
			}
		}

		return result;
	}
};




int main()
{
	Solution testCase;

	vector<int> Prices = { 1, 2, 3, 5, 0, 2, 1 };
	
	cout << testCase.maxProfit(Prices)<<endl;

	getchar();
	return 0;
}
