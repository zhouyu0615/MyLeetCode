#include <iostream>
#include <vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		unordered_map<int, int> countMap; //key为num,val为出现的次数//

		vector<int> result;

		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			countMap[nums[i]]++;
		}

		unordered_map<int, int>::iterator pI;
		for (pI = countMap.begin(); pI != countMap.end(); ++pI)
		{
			if (pI->second>(len / 3))
			{
				result.push_back(pI->first);
			}
		}
		return result;
	}
};


class Solution2 {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
		{
			return nums;
		}

		int result1 = nums[0], result2 = nums[1];
		int count1 = 0, count2 = 0;

		for (int i = 0; i < len; ++i)
		{
			if (result1 == nums[i])
			{
				count1++;
			}
			else if (result2 == nums[i])
			{
				count2++;
			}
			else if (count1 == 0)
			{
				result1 = nums[i];
				count1 = 1;
			}
			else if (count2 == 0)
			{
				result2 = nums[i];
				count2 = 1;
			}
			else
			{
				count1--;
				count2--;
			}
		}
		count1 = count2 = 0;
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == result1)
			{
				count1++;
			}
			else if (nums[i] == result2)
			{
				count2++;
			}
		}
		vector<int> result;
		if (count1>(len / 3))
		{
			result.push_back(result1);
		}
		if (count2 > (len / 3))
		{
			result.push_back(result2);
		}
		return result;
	}
};



int main()
{
	vector<int> nums = { 2,2 };

	Solution2 testCase;

	vector<int> result = testCase.majorityElement(nums);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	getchar();
	return 0;
}