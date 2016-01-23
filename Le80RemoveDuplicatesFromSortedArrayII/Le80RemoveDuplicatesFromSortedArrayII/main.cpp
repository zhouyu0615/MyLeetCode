#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		vector<int>::iterator pIter;
		if (nums.size()<=1)
		{
			return nums.size();
		}
		int numCount = 0;
		for (pIter = nums.begin()+1; pIter != nums.end();)
		{
			numCount++;
			if (*pIter!=*(pIter-1))
			{
				numCount = 0;
				++pIter;
			}
			else
			{
				if (numCount>=2)
				{
					pIter=nums.erase(pIter);
				}
				else
				{
					++pIter;
				}
			}
		}	
		return nums.size();
	}
};

int main()
{


	vector<int> Nums = { 1, 1, 1, 2, 2, 3, 3, 3, 3 };
	
	Solution testCase;

	testCase.removeDuplicates(Nums);

	for each (int var in Nums)
	{
		cout << var << " ";
	}
	cout << endl;

	getchar();
	return 0;
}


