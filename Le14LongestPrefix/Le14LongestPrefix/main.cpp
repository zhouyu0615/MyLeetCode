#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{

		if (strs.size()==0||strs[0].size()==0)
		{
			return "";
		}

		string prefix=strs[0];

		size_t i, j;

		for (i = 1; i < strs.size();i++)
		{
			string tempstr = strs[i];
			if (tempstr.length() == 0)
			{
				return "";
			}

			int len = (prefix.size() <   tempstr.size() ? prefix.size() : tempstr.size());

			for (j = 0; j < len;j++)
			{
				if (prefix[j] != tempstr[j])
				{
					break;
				}
				
			}

			prefix = prefix.substr(0, j);

		}
		return prefix;

	}
};




int main()
{
	Solution test;

	vector<string>  strs;
	strs.push_back("abcda");
	strs.push_back("abc");
	strs.push_back("a");

	cout << "result=" << test.longestCommonPrefix(strs);


	getchar();
	
	return 0;
}








