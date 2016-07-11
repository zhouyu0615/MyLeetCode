#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool isMatch(char* str, char* pattern) {

		if (*pattern=='\0')
		{
			return *str == '\0';
		}

		if (*(pattern + 1) != '*')
		{
			if (*pattern==*str||(*pattern)=='.'&&(*str!='\0'))
			{
				return isMatch(str + 1, pattern + 1);
			}
			return false;
		}
		else
		{
			while (*pattern == *str || ((*pattern) == '.' && (*str) != '\0'))
			{
				if (isMatch(str,pattern+2))
				{
					return true;
				}
				str++;
			}
			return isMatch(str, pattern + 2);
		}
	}
};



class Solution {
public:
	bool isMatch(string s, string p) {
		
		char* str = (char*)s.c_str();
		char* pattern = (char*)p.c_str();

		return matchCore(str, pattern);

	}
private:
	bool matchCore(char* str, char* pattern)
	{
		if (*pattern=='\0')
		{
			return *str == '\0';
		}

		if (*(pattern+1)=='*')
		{
			if (*pattern==*str||(*pattern=='.'&&*str!='\0'))
			{
				return matchCore(str + 1, pattern + 2) 
					|| matchCore(str + 1, pattern)
					|| matchCore(str, pattern + 2);
			}
			else
			{
				return matchCore(str, pattern + 2);
			}
		}


		if (*str==*pattern||(*pattern=='.'&&*str!='\0'))
		{
			return matchCore(str + 1, pattern + 1);
		}
		return false;
	}
};




int main()
{

	getchar();
	return 0;
}