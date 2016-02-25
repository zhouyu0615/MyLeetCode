#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		
		if (amount == 0) return 0;
		if (coins.size() == 0) return -1;

		vector<unsigned int> MinDp;
		MinDp.assign(amount + 1, amount+1);
		MinDp[0] = 0;

		
		for (int i = 0; i <= amount;i++)
		{
			for (int j = 0; j < coins.size();j++)
			{
				if (i>=coins[j])
				{
					MinDp[i] = Min(MinDp[i], MinDp[i - coins[j]] + 1);
				}		
			}
		}
		return MinDp[amount] > amount ? -1 : MinDp[amount];
	}
private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};





int main()
{
	vector<int> coins = { 186,419,83,408 };

	Solution testCase;

	cout << testCase.coinChange(coins,6249) << endl;
	
	getchar();
	return 0;
}