#include <iostream>

using namespace std;


class Solution {
public:
	bool isUgly(int num) {
		if (num<1)
		{
			return false;
		}
		int number = num;
		while (number % 2 == 0)
		{
			number = number / 2;
		}

		while (number % 3 == 0)
		{
			number = number / 3;
		}

		while (number % 5 == 0)
		{
			number = number / 5;
		}

		return number == 1 ? true : false;
	}
};


int main()
{

	Solution testCase;

	cout << testCase.isUgly(17) << endl;

	getchar();
	return 0;
}

