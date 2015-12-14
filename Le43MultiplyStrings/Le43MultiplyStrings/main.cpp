#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length();
		int len2 = num2.length();

		int len = len1 + len2+1;

		int *number1 = new int[len1];
		int *number2 = new int[len2];

		string strRes = "";
		int *result = new int[len];
		memset(result, 0, sizeof(int)*len);

		for (int i = 0; i < len1;i++)
		{
			number1[len1-i-1] = num1[i] - '0';
		}
		for (int i = 0; i < len2; i++)
		{
			number2[len2-i-1] = num2[i] - '0';
		}

		for (int i = 0; i < len1;i++)
		{
			for (int j = 0; j < len2;j++)
			{
				result[i + j] += number1[i] * number2[j];			
			}
		}
		
	
		for (int i = 0; i < len-1;i++)
		{
			int tmp = result[i] / 10;
			
			result[i] = result[i] % 10;
			result[i + 1] += tmp;

			char c =result[i] + '0';
			strRes += c;
		}	
		reverse(strRes.begin(), strRes.end());
		int pos=strRes.find_first_not_of("0");
		strRes = pos>=0?strRes.substr(pos):"0";
		return strRes;
	}
};


int main()
{

	Solution testCase;

	cout << testCase.multiply("123456", "123") << endl;


	getchar();
	return 0;
}
