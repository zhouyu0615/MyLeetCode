#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {

		int len = s.length();
		if (len <= 1) return true;
		int i = 0;
		int j = len - 1;

		while (i<j)
		{
			while (!isVaild(s[i])&&i<=j)
			{
				i++;
			}
			while (!isVaild(s[j])&&i<=j)
			{
				j--;
			}

			if (i >= j) return true;

			if (toLower(s[i]) != toLower(s[j]))
			{
				return false;
			}
			i++;
			j--;
		}
		return true;

	}
private:
	bool isVaild(char c)
	{
		if ((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			return true;
		}
		return false;
	}

	char toLower(char c)
	{
		if (c >= 'A'&&c <= 'Z')
		{
			return c - 'A' + 'a';
		}
		return c;
	}
};

int main()
{


	getchar();
	return 0;
}