#include <iostream>


class Solution {
public:
	bool isPowerOfFour(int num) {

		int count = 0;
		int numOf1Bits = 0;
		for (int i = 0; i < 32;i++)
		{
			if (num&(1<<i))
			{
				numOf1Bits++;
				if (i%2==0)
				{
					count++;
				}
			}
			if (numOf1Bits>1)
			{
				return false;
			}
		}

		return count == 1 ? true : false;
	}
};

using namespace std;
int main()
{
	Solution testCase;
	int num = 0;
	while (cin>>num)
	{
		cout << testCase.isPowerOfFour(num)<<endl;
	}
	

	getchar();
	return 0;
}