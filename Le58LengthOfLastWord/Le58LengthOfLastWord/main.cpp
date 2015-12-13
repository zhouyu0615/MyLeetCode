#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int count = 0;
		if (len==0)
		{
			return len;
		}

		int lastPos = len-1;
		while (s[lastPos]==' ')
		{
			lastPos--;
		}
		for (int i = lastPos; i >= 0; i--)
		{
			if (s[i]==' ')
			{
				break;
			}
			count++;
		}

		return count;
	}
};


int main()
{

	string str="hello World";
	Solution testCase;

	while (str!="quit")
	{
		getline(cin,str);
		cout << testCase.lengthOfLastWord(str);
	}
	getchar();
	return 0;
}