#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int maxLen = GetMaxLen(wordDict);

		vector<int> DpFlag;
		int len = s.length();

		DpFlag.assign(len + 1, 0);

		DpFlag[0] = 1;
		for (int i = 0; i < len;i++)
		{
			if (DpFlag[i])
			{
				for (int size = 1; i + size - 1 < len&&size<=maxLen;size++)
				{
					if (wordDict.count(s.substr(i,size))>0)
					{
						DpFlag[i + size] = 1;
					}
				}
			}
		}

		return DpFlag[len];
	}
private:
	int GetMaxLen(unordered_set<string>& wordDict)
	{
		unordered_set<string>::iterator pI;
		int maxLen = 0;
		for (pI = wordDict.begin(); pI != wordDict.end();++pI)
		{
			maxLen = Max(maxLen, pI->length());
		}
		return maxLen;
	};

	inline int Max(int a, int b){ return a > b ? a : b; };
};


int main()
{

	getchar();
	return 0;
}