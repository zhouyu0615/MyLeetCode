#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	string longestPalindrome(string s) {
		size_t strLen = s.size();
		bool table[1000][1000] = {false};

		int maxLen = 1;
		int startPos=0;

		for (int i = 0; i < strLen;i++)
		{
			table[i][i] = true;
			if (i+1<strLen)
			{
				if (s[i]==s[i+1])
				{
					table[i][i + 1] = true;
					startPos = i;
					maxLen = 2;
				}
			}
		}

		//判断len长度是否为回文字符
		for (int len = 3; len <= strLen;len++)
		{
			for (int i = 0; i < strLen - len + 1;i++)
			{
				int j = i + len - 1;
		         if ((table[i+1][j-1]==true)&&s[i]==s[j])
		         {
					 table[i][j] = true;
					 int curLen = j - i + 1;
					 if (curLen>maxLen)
					 {
						 maxLen = curLen;
						 startPos = i;
					 }
		         }
			}
		}

		return s.substr(startPos, maxLen);
	}
};


int main()
{
	Solution testCase;
	string str = "aa";
	
	cout << testCase.longestPalindrome(str) << endl;

	getchar();
	return 0;
}