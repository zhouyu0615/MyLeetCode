#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
	{
		map<int, int> num1Map;
		map<int, int>  num2Map;

		for (int i = 0; i < nums1.size();i++)
		{
			num1Map[nums1[i]]++;
		}
		for (int i = 0; i < nums2.size(); i++)
		{
			num2Map[nums2[i]]++;
		}

		map<int, int>::iterator pIter;
		
		vector<int> result;
		for (pIter=num1Map.begin(); pIter != num1Map.end();++pIter)
		{
		

			int len = Min(pIter->second,num2Map[pIter->first]);
			for (int i = 0; i < len;i++)
			{
				result.push_back(pIter->first);
			}
		}
		return result;

	}

	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};


int main()
{
	vector<int> num1 = {1,2,2,2,1};
	vector<int> num2 = {2,2};

	Solution testCase;
	testCase.intersect(num1, num2);

	getchar();
	return 0;
}

