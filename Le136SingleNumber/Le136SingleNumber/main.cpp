#include <iostream>
#include <vector>
#include <map>


using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int,int> poolMp;
		for (int i = 0; i < nums.size();i++)
		{
			poolMp[nums[i]]++;
		}

		map<int, int>::iterator pI;
		for (pI = poolMp.begin(); pI != poolMp.end(); ++pI)
		{
			if (pI->second==1)
			{
				return pI->first;
			}
		}

	}
};



class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		int temp = 0;
		if (nums.size()>0)
		{
			temp = nums[0];
			for (int i = 1; i < nums.size();i++)
			{
				temp = temp^nums[i];
			}
		}
		
		return temp;
	}

};




int main()
{
	Solution2 testCase;
	vector<int> nums = { 1, 2, 3, 1, 2, 3, 4, 5, 5, 6, 6 };
	cout<<testCase.singleNumber(nums);


	getchar();
	return 0;
}