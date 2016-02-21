#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		int len = s.length();	
		palDp.assign(len, vector<char>(len, 0));

		//palDp[i][j]=1,表示字符串从i到j为回文字符//
		for (int i = len-1; i>=0;i--)
		{
			for (int j = i; j < len;j++)
			{
				if (i==j)
				{
					palDp[i][j] = 1;
				}
				else
				{
					if (s[i]==s[j])
					{
						if ((j==i+1)||palDp[i+1][j-1]==1) //i与j之间无字母或者中间有回文字符串//
						{
							palDp[i][j] = 1;
						}
						
					}
				}
			}
		}


		vector<string> palString;

		DfsAdd(0, s, palString);

		return result;
	}
private:
	vector<vector<string>>  result;
	vector<vector<char>> palDp;

	void DfsAdd(int start,string& s,vector<string>& palstrings)
	{
		if (start==s.length())
		{
			result.push_back(palstrings);
			return;
		}
		else
		{
			for (int i = start; i < s.length();i++)
			{
				if (palDp[start][i]==1)
				{
					palstrings.push_back(s.substr(start, i - start + 1));
					DfsAdd(i + 1, s, palstrings);
					palstrings.pop_back();
				}

			}
		}
	}

};


int main()
{
	vector<vector<string>> result;
	Solution testCase;

	result = testCase.partition("aab");

	for (int i = 0; i < result.size();i++)
	{
		for (int j = 0; j < result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	
	getchar();
	return 0;
}
