#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {

		int len = nums.size();
		if (len <= 1) return false;
	
		set<int> numsSet;
		for (int i = 0; i < len;i++)
		{
			if (numsSet.count(nums[i])==0)
			{
				numsSet.insert(nums[i]);
			}
			else
			{
				return true;
			}
		}		
		return false;
	}
};

int main()
{
	Solution testCase;
	vector<int> nums = { 3, 1 };

	cout << testCase.containsDuplicate(nums) << endl;

	getchar();
	return 0;
}