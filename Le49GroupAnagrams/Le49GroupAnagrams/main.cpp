#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;




class Solution {

private:

static bool Compare(string &str1, string &str2)
	{
		int len = (str1.length() < str2.length() ? str1.length() : str2.length());

		for (int i = 0; i < len; i++)
		{
			if (str1[i] == str2[i]) continue;
			return str1[i] < str2[i];
		}
	}

public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;

		std::sort(strs.begin(), strs.end(), Compare);

		map < char, int > charkey; //key为出现的字符，val为出现字符的次数
		map < map<char, int>, vector<string>> strMap ;
		map < map<char, int>, vector<string>>::iterator pIterMap;

		for (int i = 0; i < strs.size();i++)
		{
			charkey.clear();
			for (int j = 0; j < strs[i].size(); j++)
			{
				charkey[strs[i][j]]++;
			}
			strMap[charkey].push_back(strs[i]);
		}

		for (pIterMap = strMap.begin(); pIterMap != strMap.end();++pIterMap)
		{
			result.push_back(pIterMap->second);
		}

		return result;
	}
};



int main()
{

	Solution test;
	vector<string> strs = { "ate", "tea", "aet", "abd" };

	vector<vector<string>> res;
	vector<vector<string>>::iterator pIter;
	vector<string>::iterator It;

	res = test.groupAnagrams(strs);


	for (pIter = res.begin(); pIter != res.end();++pIter)
	{
		for (It = pIter->begin(); It != pIter->end();++It)
		{
			cout << *It << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}


