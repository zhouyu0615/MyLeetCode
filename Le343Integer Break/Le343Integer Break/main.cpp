#include <iostream>


using namespace std;

class Solution {
public:
	int integerBreak(int n) {

		int result=1;

		if (n <= 2) return 1;
		if (n == 3) return 2;
		while (n>=3)
		{
			n = n - 3;
			result = 3 * result;
		}

		if (n == 1) return (result / 3 * 4);
		if (n == 2) return result * 2;	

		return result;
	}
};


int main()
{
	Solution testCase;

	int num=0;
	while (cin>>num)
	{
		cout << testCase.integerBreak(num) << endl;
	}

	getchar();
	return 0;
}