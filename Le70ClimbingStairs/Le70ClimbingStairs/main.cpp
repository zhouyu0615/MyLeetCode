#include <iostream>
#include <vector>

using namespace std;





class Solution {
public:
	int climbStairs(int n) {
		vector<int> sumMethods;

		sumMethods.assign(n, 0);


		sumMethods[0] = 1;
		sumMethods[1] = 2;
		for (int i = 2; i < n;i++)
		{
			sumMethods[i] = sumMethods[i - 1] + sumMethods[i - 2];
		}
		return sumMethods[n-1];
	}
};





int main()
{

	Solution testCase;

	cout << testCase.climbStairs(5);


	getchar();
	return 0;
}


