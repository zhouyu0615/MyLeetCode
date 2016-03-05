#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		int len = nums.size();
		if (len <= 0||k==0) return false;

		unordered_map<int, int> numsMap; //keyΪnums[i],ֵΪ����//
		
		for (int i = 0; i < len;i++)
		{
			if (numsMap.count(nums[i])==0)
			{
				numsMap[nums[i]] = i;
			}
			else 
			{
				if (i-numsMap[nums[i]]<=k)
				{
					return true;
				}
				else
				{
					numsMap[nums[i]] = i;//��������//
				}
			}

		}
		return false;
	}
};




int main()
{

	getchar();
	return 0;
}

