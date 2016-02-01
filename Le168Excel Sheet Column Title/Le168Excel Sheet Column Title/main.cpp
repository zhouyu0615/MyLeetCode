#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	string convertToTitle(int n) {

		string strRes;
		char stemp;
		int temp = 0;
		while (n > 0)
		{
			temp = n % 26;
			if (temp == 0)
			{
				temp = 26;
				n = n - 1;
			}
			stemp = 'A' - 1 + temp;
			n = n / 26;
			strRes = strRes + stemp;
		}
		reverse(strRes.begin(), strRes.end());

		return strRes;
	}
};


class Solution2 {
public:
	string convertToTitle(int n) {

		string strRes;
		char stemp;
		int temp = 0;
		while (n > 0)
		{
			temp = (n-1) % 26;

			stemp = 'A'  + temp;
			n = (n-1) / 26;
			strRes = stemp+strRes;
		}
		return strRes;
	}
};



int main()
{
	Solution2 testCase;

	cout << testCase.convertToTitle(52) << endl;

	getchar();
	return 0;
}