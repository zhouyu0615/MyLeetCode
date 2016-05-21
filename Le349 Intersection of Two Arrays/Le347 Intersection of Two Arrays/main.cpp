#include <iostream>
#include <vector>
#include <set>


using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		
		set<int> num1Set;
		set<int> resultSet;
		for (int i = 0; i < nums1.size();i++)
		{
			num1Set.insert(nums1[i]);
		}

		for (int i = 0; i < nums2.size();i++)
		{
			if (num1Set.count(nums2[i])!=0)
			{
				resultSet.insert(nums2[i]);
			}
		}

		vector<int> result;
		set<int>::iterator pIter;
		for (pIter = resultSet.begin(); pIter != resultSet.end();++pIter)
		{
			result.push_back(*pIter);
		}
		return result;
	}
};


int main()
{

	getchar();
	return 0;
}