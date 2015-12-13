#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;




class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		map<char,int> PoolMap;

		int maxLength=0;
		int start = -1;

		for (size_t i = 0; i < s.length();i++)
		{
			if (PoolMap.count(s[i])!=0) //��ǰ�ַ��Ѿ�����ʱ//
			{
				start = max(start, PoolMap[s[i]]);//��ǰ�ַ����ֵ������һ��//				
			}
			PoolMap[s[i]] = i;
			maxLength = max(maxLength, i - start);
		}
	
		return maxLength;
	}

	inline int max(int a, int b)
	{
		return a > b ? a : b;
	}

};






int main()
{

	Solution testCase;

	
	cout << "result= " << testCase.lengthOfLongestSubstring("aau") << endl;;




	getchar();

	return 0;
}

