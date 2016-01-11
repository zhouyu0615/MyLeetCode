#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0) return 0.;

		int low = prices[0]; //保留最小价格//

		int result = 0;

		for (int i = 0; i < len;i++)
		{
			if (low>prices[i])
			{
				low = prices[i];
			}
			else
			{
				 if ((prices[i]-low)>result)
				 {
					 result = prices[i] - low;
				 }
			}		
		}
		return result;

	}
};



int main()
{

	Solution testCase;

	vector<int> prices = { 4,1,2};
	cout << testCase.maxProfit(prices);


	getchar();
	return 0;
}

