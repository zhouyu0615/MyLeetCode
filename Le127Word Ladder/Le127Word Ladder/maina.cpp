#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <map>


using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if (beginWord==""||endWord==""||beginWord==endWord||beginWord.length()!=endWord.length())
		{
			return 0;
		}
		queue<string> strQueue;
		map<string, int> distMap;//key为字符串，val为路径步数//

		strQueue.push(beginWord);
		distMap[beginWord] = 1;

		int len = beginWord.length();
		string Headstr;
		string temp;
		int distStep=1;
		while (!strQueue.empty())
		{
			Headstr = strQueue.front();
			strQueue.pop();
			distStep = distMap[Headstr];
			distStep++;
			for (int i = 0; i < len;i++)
			{
				temp = Headstr;
				//依次替换各个字母//
				for (int c = 'a'; c <= 'z'; c++)
				{
					temp[i] = c;
					if (temp==Headstr) continue;
					if (temp == endWord)
					{
						return distStep;
					}
					//替换掉字母后的字符串位于字典中,并且字符串在路径中还没有出现//
					if (wordList.count(temp)!=0&&(distMap.find(temp)==distMap.end()))
					{
						strQueue.push(temp);
						distMap[temp] = distStep;
					}
				}

			}

		}
		return 0;
	}

private:
	//判断两个字符串之间是否只有一个字母的差距//
	bool isOneWordDiff(string str1, string str2)
	{
		int diff = 0;
		int len = str1.length();
		for (int i = 0; i < len;i++)
		{
			if (str1[i]!=str2[i])
			{
				diff++;
			}
			if (diff>=2)
			{
				return false;
			}
		}
		return diff==1?true:false;
	}
};



int main()
{


	getchar();
	return 0;
}