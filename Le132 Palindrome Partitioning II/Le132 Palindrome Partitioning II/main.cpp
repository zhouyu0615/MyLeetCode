#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		palDp.assign(len, vector<char>(len, 0));

		minCuts = len;

		//palDp[i][j]=1,��ʾ�ַ�����i��jΪ�����ַ�//
		for (int i = len - 1; i >= 0; i--)
		{
			for (int j = i; j < len; j++)
			{
				if (i == j)
				{
					palDp[i][j] = 1;
				}
				else
				{
					if (s[i] == s[j])
					{
						if ((j == i + 1) || palDp[i + 1][j - 1] == 1) //i��j֮������ĸ�����м��л����ַ���//
						{
							palDp[i][j] = 1;
						}

					}
				}
			}
		}


		vector<string> palString;
		DfsAdd(0, s, palString);

		return minCuts-1;
	}
private:
	vector<vector<char>> palDp;
	int minCuts;

	void DfsAdd(int start, string& s, vector<string>& palstrings)
	{
		if (start == s.length())
		{
			minCuts = (minCuts > palstrings.size() ? palstrings.size() : minCuts);
			return;
		}
		else
		{
			for (int i = start; i < s.length(); i++)
			{
				if (palDp[start][i] == 1)
				{
					if (palstrings.size()>=minCuts)
					{
						continue;
					}
					palstrings.push_back(s.substr(start, i - start + 1));
					DfsAdd(i + 1, s, palstrings);
					palstrings.pop_back();
				}

			}
		}
	}
};



class Solution2 {
public:
	int minCut(string s) {
		int len = s.length();
		vector<vector<char>> palDp;
		palDp.assign(len, vector<char>(len, 0));
		//palDp[i][j]=1,��ʾ�ַ�����i��jΪ�����ַ�//

		vector<int> CutCount; //cutCount[i]��ʾ�Ӻ���ǰ����iʱ���ж��ٸ��ֶ�//
		CutCount.assign(len + 1, 0);

		for (int i = len - 1; i >= 0; i--)
		{
			CutCount[i] = len;
			for (int j = i; j < len; j++)
			{			

				if (s[i] == s[j])
				{
					if (j==i||(j == i + 1)|| palDp[i + 1][j - 1] == 1) //i��j֮������ĸ�����м��л����ַ���//
					{
						palDp[i][j] = 1;
						CutCount[i] = Min(CutCount[j + 1] + 1, CutCount[i]);
					}
				}
			}
		}

		return CutCount[0] - 1;

	}

private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};



class Solution3 {
public:
	int minCut(string s) {
		int len = s.length();
		vector<vector<char>> palDp;
		palDp.assign(len, vector<char>(len, 0));
		//palDp[i][j]=1,��ʾ�ַ�����i��jΪ�����ַ�//

		vector<int> CutCount; //cutCount[i]��ʾ�Ӻ���ǰ����iʱ���ж��ٸ��ֶ�//
		CutCount.assign(len + 1, 0);

		for (int i = len - 1; i >= 0; i--)
		{
			CutCount[i] = len;
			for (int j = i; j < len; j++)
			{

				if (s[i] == s[j])
				{
					if (j == i || (j == i + 1) || palDp[i + 1][j - 1] == 1) //i��j֮������ĸ�����м��л����ַ���//
					{
						palDp[i][j] = 1;
					}
				}
			}
		}

		for (int i = 0; i < len;i++)
		{
			CutCount[i+1] = len;
			for (int j = i; j < len;j++)
			{
				if (palDp[i][j]==1)
				{
					CutCount[i] = Min(CutCount[j - 1] + 1, CutCount[i]);
				}
			}
		}

		return CutCount[len] - 1;
	}

private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};



int main()
{
	vector<vector<string>> result;
	Solution2 testCase;

	long start = GetTickCount();
	cout << testCase.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;
	
	long finish = GetTickCount();

	cout << "��ʱ:" << finish - start << "ms" << endl;
	getchar();
	return 0;
}
