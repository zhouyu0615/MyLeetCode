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
		map<string, int> distMap;//keyΪ�ַ�����valΪ·������//

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
				//�����滻������ĸ//
				for (int c = 'a'; c <= 'z'; c++)
				{
					temp[i] = c;
					if (temp==Headstr) continue;
					if (temp == endWord)
					{
						return distStep;
					}
					//�滻����ĸ����ַ���λ���ֵ���,�����ַ�����·���л�û�г���//
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
	//�ж������ַ���֮���Ƿ�ֻ��һ����ĸ�Ĳ��//
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