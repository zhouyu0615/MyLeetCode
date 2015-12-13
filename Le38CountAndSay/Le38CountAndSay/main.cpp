#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	string countAndSay(int n) {
		
		string strResult = "1";
		int j = 1;
		
		while (j<n)
		{
			strResult = ProduceString(strResult);
			j++;
		}
		return strResult;
	}
private:
	string ProduceString(string str)
	{
		string strResult;
		int len = str.size();

		int count = 1;
		char preChar=str[0];
		for (int i = 1; i < len;i++)
		{
			if (str[i]==preChar)
			{
				count++;
			}
			else
			{             
				char tmp = count + '0';
				strResult = strResult + tmp + preChar;
				count = 1;
				preChar = str[i];
			}
		}
		char tmp = count + '0';
		strResult = strResult + tmp + preChar;

		return strResult;
	}

};


int main()
{
	Solution testCase;

	cout << testCase.countAndSay(15)<<endl;



	getchar();
	return 0;
}
