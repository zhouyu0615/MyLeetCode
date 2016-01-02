#include <iostream>
#include <string>


using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {

		string& ShortStr = (a.length() < b.length() ? a : b);
		string& LongStr = (a.length() <b.length() ? b : a);
		int minLen = ShortStr.length();
		int maxLen = LongStr.length();

		for (int i = 0; i<minLen;i++) 
		{
			LongStr[maxLen - minLen + i] = (ShortStr[i] - '0') + (LongStr[maxLen - minLen + i] - '0') + '0';
		}

		for (int i = maxLen - 1; i > 0;i--)
		{
			if ((LongStr[i] - '0') >= 2)
			{
				LongStr[i] = (LongStr[i] - '0') % 2+'0';
				LongStr[i - 1] = LongStr[i - 1] + 1;
			}
		}
		if ((LongStr[0]-'0')>=2)
		{
			string str = "1";
			LongStr[0] = ((LongStr[0]-'0') % 2) + '0';
			str.append(LongStr);
			return str;
		}
		else
		{
			return LongStr;
		}

	}
};


int main()
{
	Solution testCase;
	string a = "110";
	string b = "11";
	cout << testCase.addBinary(a, b)<<endl;


	getchar();
	return 0;
}



