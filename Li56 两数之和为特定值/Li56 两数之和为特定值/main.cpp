#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
	/*
	* @param numbers : An array of Integer
	* @param target : target = numbers[index1] + numbers[index2]
	* @return : [index1+1, index2+1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		vector<int> result = {-1,-1};
		int len = nums.size();
		if (len<2)
		{
			return result;
		}
		multimap<int, int> indexMap; //key为值，val为位置索引//
		for (int i = 0; i < len;i++)
		{
			indexMap.insert(make_pair(nums[i],i+1));
		}
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len;i++)
		{
			if (binSearch(nums,target-nums[i]))
			{
				if (target-nums[i]==nums[i])
				{
					multimap<int, int>::iterator beg = indexMap.find(nums[i]);
					int a = beg->second;
					beg++;
					int b = beg->second;
					result[0]=Min(a, b);
					result[1]=Max(a, b);
				}
				else
				{
					result[0]=(Min(indexMap.find(nums[i])->second, indexMap.find(target - nums[i])->second));
					result[1]=(Max(indexMap.find(nums[i])->second, indexMap.find(target - nums[i])->second));
				}		
				return result;
			}
		}
		return result;
	}
private:
	bool binSearch(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left<=right)
		{
			mid = (left + right) / 2;

			if (nums[mid]==target)
			{
				return true;
			}
			else if (nums[mid]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return false;
	}

	inline int Max(int a, int b){ return a > b ? a : b; }
	inline int Min(int a, int b){ return a < b ? a : b; }
};

int main()
{
	getchar();
	return 0;
}