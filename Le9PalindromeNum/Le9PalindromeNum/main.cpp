#include <iostream>


using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
		{
			return false;
		}

		int base = 1;
		int temp = 0;
		temp = x;
		while (temp>=10)
		{
			temp = temp / 10;
			base = base * 10;
		}

		while (x)
		{
			int rightNum = x / base; //当前最高位//
			int leftNum = x % 10;     //当前最低位//

			if (rightNum!=leftNum)
			{
				return false;
			}
			x = (x - rightNum*base) / 10; //去掉当前最高位和最低位//
			base = base / 100;
		}

		return true;
	}
};



int main()
{
	Solution test;

	cout << "Result= " << test.isPalindrome(1000021) << endl;



	getchar();
	return 0;
}