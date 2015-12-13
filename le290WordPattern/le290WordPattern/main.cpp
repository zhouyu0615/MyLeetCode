#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <sstream>
#include <vector>


using namespace std;


class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> mp;
		istringstream  iss(str);
		
		char chars[26] = { 0 };
		int pos = 0;


		string temstr;

		while (getline(iss, temstr, ' '))
		{
			if (pos>=pattern.length())
			{
				return false;
			}

			if (mp.count(temstr))//map���Ѿ����ڸ�temstr//
			{
				if (mp[temstr]!=pattern[pos])
				{
					return false;
				}
			}
			else   //�����������temstr���뵽map��//
			{
				if (chars[pattern[pos]-'a']==1) //�µ�temstr��Ӧ��pattern����ĸ�Ѿ�����//
				{
					return false;
				}
		
				mp[temstr] = pattern[pos];
				chars[pattern[pos] - 'a'] = 1;  //���λ

			}
			pos++;
		}
		return pos == pattern.length();
	}
};



class Solution2 {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> mp;
		set<string> pool;

		istringstream  iss(str);
		string tempstr;
		int pos = 0;	
		while (getline(iss, tempstr, ' '))
		{
			if (pos >= pattern.length())
			{
				return false;
			}
			if (mp.count(pattern[pos]) == 0)
			{
				if (pool.count(tempstr)==0)
				{
					mp[pattern[pos]] = tempstr;
					pool.insert(tempstr);
				}			
			}
			if (mp[pattern[pos]]!=tempstr)
			{
				return false;
			}
			pos++;
		}
		return pos == pattern.length();
	}
		
};






int main()
{

	string partten = "abba";
	string str = "dog dog dog dog";

	Solution2 test;

	if (test.wordPattern(partten, str)==true)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

	getchar();


	return 0;
}