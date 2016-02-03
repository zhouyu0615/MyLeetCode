#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Solution {
public:
	int numDecodings(string s) {
		vector<int> dpNums;
		int len = s.length();
		dpNums.assign(len, 0);

		if (len==0)
		{
			return 0;
		}else if (len==1)
		{
			return s[0] != '0' ? 1 : 0;
		}else if (len>=2)
		{		
			dpNums[0] = (s[0] != '0' ? 1 : 0);
			dpNums[1] = (((s[0] != '0' && s[1] != '0')) ? 1 : 0) +(s[0] != '0' && (CharToInt(s[0]) * 10 + CharToInt(s[1]) <= 26) ? 1 : 0);
		}

		for (int i = 2; i < len;i++)
		{
			if (CharToInt(s[i])!=0)
			{
				dpNums[i] = dpNums[i - 1];
			}
			if ((s[i-1]!='0')&&(CharToInt(s[i-1])*10+CharToInt(s[i]))<=26)
			{
				dpNums[i] = dpNums[i] +dpNums[i-2];
			}

		}

		return dpNums[len - 1];
	}
private:
	inline int CharToInt(char c)
	{
		return c - '0';
	}

};



int main()
{
	Solution testCase;

	cout << testCase.numDecodings("000") << endl;


	getchar();
	return 0;
}