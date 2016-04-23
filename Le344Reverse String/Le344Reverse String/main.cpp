#include <iostream>
#include <string>


using namespace std;


class Solution {
public:
	string reverseString(string s) {

		int len = s.length();
		if (len<=1)
		{
			return s;
		}

		int i = 0;
		int j = len - 1;

		while (i<j)
		{
			Swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
private:
	void Swap(char&a, char &b)
	{
		char temp;
		temp = a;
		a = b;
		b = temp;
		return;
	}
};



int main()
{
	Solution testCase;

	string Str;
	while (cin>>Str)
	{
		cout << testCase.reverseString(Str) << endl;
	}


	getchar();
	return 0;
}