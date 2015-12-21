#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>


using namespace std;




class Solution {
public:
	string removeDuplicateLetters(string s) {
		int n = s.length();
		char* str = (char*)malloc(n+1);//str[n + 1];
		strcpy(str, s.c_str()); // convert string to char array

		int i;
		vector<int> count(26, 0); // map a-z to 0-25
		for (i = 0; i < n; i++)
			count[str[i] - 'a']++;

		vector<char> res; // char vector version of the result string
		vector<int> inres(26, 0); // inres[i]: whether char (i+'a') is in res
		for (i = 0; i < n; i++)
		{
			if (res.size() == 0)
			{
				res.push_back(str[i]);
				inres[str[i] - 'a'] = 1;
				count[str[i] - 'a']--;
				continue;
			} // if empty res, push str[i] to res anyhow
			if (inres[str[i] - 'a'] == 1)
			{
				count[str[i] - 'a']--;
				continue; // if(str[i] already in res), skip
			}
			if (count[str[i] - 'a'] == 0)
				continue;
			while (res.size()>0 && str[i] < res.back() && count[res.back() - 'a'] > 0)
			{
				inres[res.back() - 'a'] = 0;
				res.pop_back();
			} // updating to lexicographical order
			res.push_back(str[i]);
			count[str[i] - 'a']--;
			inres[str[i] - 'a'] = 1;
		}
		string result;
		for (i = 0; i < res.size(); i++)
			result = result + res[i];
		return result;
	}
};

int main()
{
	Solution testCase;

	cout << testCase.removeDuplicateLetters("cbacdcbc") << endl;

	getchar();
	return 0;
}