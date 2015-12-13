#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
	int myAtoi(string str) {

		long long   Value=0;
		int sign=1;

		size_t i = str.find_first_not_of(' ');

		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i]=='+')
		{
			i++;
		}

		for (; i<str.length();i++)
		{
			if (str[i]>='0'&&str[i]<='9')
			{
				Value = Value * 10 + (str[i] - '0');
				
				if (sign*Value>INT_MAX)
				{
					return INT_MAX;
				}

				if (sign*Value < INT_MIN)
				{
					return INT_MIN;
				}
			}
			else
			{
				break;
			}
		}
		return (int)sign*Value;
	}
};


int main()
{

	Solution test;

	cout << "result=" << test.myAtoi("-123") << endl;

	getchar();
	return 0;
}

