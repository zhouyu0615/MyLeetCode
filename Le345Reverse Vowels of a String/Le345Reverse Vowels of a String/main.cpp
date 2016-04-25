#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	string reverseVowels(string s) {

		int len = s.length();
		if (len<=1)
		{
			return s;
		}
		int i = 0;
		int j = len - 1;

		while (i<j)
		{
	        while (j>i&&(!isVowels(s[j])))
	        {
				j--;
	        }
			char temp = s[j];
			while (i < j&&(!isVowels(s[i])))
			{
				i++;
			}

			s[j] = s[i];
			s[i] = temp;
			j--;
			i++;
		}

		return s;
	}

private:
	bool isVowels(char s)
	{
	  if (s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
	  {
		  return true;
	  }
	  if (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
	  {
		  return true;
	  }	  
	  return false;
	}
};



int main()
{
	Solution testCase;

	string str = "hello";

	cout << testCase.reverseVowels(str) << endl;

	 
	getchar();
	return 0;
}