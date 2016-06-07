#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Solution {
public:
	int maxProduct(vector<string>& words) {
		
		int maxProduct = 0;
		convertWordsToBitMap(words);
		for (int i = 0; i < words.size();i++)
		{
			for (int j = i + 1; j < words.size();j++)
			{
				if ((stringBitMap[i]&stringBitMap[j])==0)
				{
					maxProduct = Max(maxProduct, words[i].length()*words[j].length());
				}
			}
		}
		return maxProduct;
	}
private:
	vector<int> stringBitMap;
	void convertWordsToBitMap(vector<string>& words)
	{
		for (int i = 0; i < words.size();i++)
		{
			int val = 0;
			for (int j = 0; j < words[i].length();j++)
			{
				val |= (1 << (words[i][j] - 'a'));
			}
			stringBitMap.push_back(val);
		}
		return;
	}

	inline int Max(int a, int b)
	{
		return a > b ? a : b;			
	}
};




int main()
{
	Solution testCase;
	vector<string> words= { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	//vector<string> words = { "a", "a", "b" };
	
	cout<<testCase.maxProduct(words)<<endl;

	getchar();
	return 0;
}