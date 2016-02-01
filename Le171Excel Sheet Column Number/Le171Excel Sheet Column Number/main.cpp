#include <iostream>
#include <string>


using namespace std;


class Solution {
public:
	int titleToNumber(string s) {

		int len = s.length();
		
		int Ans = 0;

		for (int i = 0; i<len;i++)
		{
			Ans = Ans*26+(s[i] - 'A' + 1);
		}

		return Ans;
	}
};


int main()
{
	Solution testCase;

	cout << testCase.titleToNumber("AB");

	getchar();
	return 0;
}