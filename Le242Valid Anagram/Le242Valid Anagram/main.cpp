#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
	bool isAnagram(string s, string t) {		

		if (s.length()!=t.length())
		{
			return false;
		}
		map<char, int> charMap1;
		map<char, int> charMap2;

		for (int i = 0; i < s.length();i++)
		{
			charMap1[s[i]]++;
			charMap2[t[i]]++;
		}


		for (int i = 0; i < s.length();i++)
		{
			if (charMap2.count(s[i])==0||charMap1[s[i]] !=charMap2[s[i]])
			{
				return false;
			}
		}

		return true;
	}
};



class Solution {
public:
	bool isAnagram(string s, string t) {
		

		if (s.length()!=t.length())
		{
			return false;
		}

		vector<int> charFlag;
		charFlag.assign(30, 0);

		for (int i = 0; i < s.length();i++)
		{
			charFlag[s[i] - 'a']++;
		}
		for (int i = 0; i < t.length(); i++)
		{
			charFlag[t[i] - 'a']--;
		}

		for (int i = 0; i < charFlag.size(); i++)
		{
			if (charFlag[i]!=0)
			{
				return false;
			}
		}
		return true;
	}
};



int main()
{


	getchar();
	return 0;
}