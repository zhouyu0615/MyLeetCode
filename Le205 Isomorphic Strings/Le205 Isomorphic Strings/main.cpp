#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length()!=t.length())
		{
			return false;
		}
		vector<int> sCode, tCode;
		GetStringCode(s, sCode);
		GetStringCode(t, tCode);

		for (int i = 0; i < sCode.size();i++)
		{
			if (sCode[i]!=tCode[i])
			{
				return false;
			}
		}
		return true;	
	}

private:
	void GetStringCode(string s, vector<int>& sCode)
	{
		map<char,int> charMap;
		for (int i = 0; i < s.length(); i++)
		{
			if (charMap.count(s[i]) == 0)
			{
				charMap.insert(make_pair(s[i],i+1));
				sCode.push_back(i+1);
			}
			else
			{
				sCode.push_back(charMap[s[i]]);
			}
		}
	}
};

int main()
{

	Solution testCase;

	cout << testCase.isIsomorphic("aba", "baa") << endl;


	getchar();
	return 0;
}

