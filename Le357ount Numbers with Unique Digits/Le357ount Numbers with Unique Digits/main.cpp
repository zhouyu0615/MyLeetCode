#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
		{
			return 1;
		}
		vector<int> dp;
		dp.push_back(10);

		for (int i = 1; i < n&&i<=10; i++)
		{
			int ans = 9;
			for (int j = 0; j < i; j++)
			{
				ans *= (9 - j);
			}
			dp.push_back(dp.back() + ans);
		}

		return dp.back();
	}
};


int main()
{



	getchar();
	return 0;
}
