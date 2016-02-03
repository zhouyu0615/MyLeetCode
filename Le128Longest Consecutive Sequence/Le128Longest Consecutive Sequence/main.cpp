#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;




class Solution {
public:
	int longestConsecutive(vector<int>& nums) {		
		int maxCount = 0;
		
		unordered_set<int> existedSet;
		unordered_set<int> visitedSet;

		for (int i = 0; i < nums.size();i++)
		{
			existedSet.insert(nums[i]);
		}

		int count = 0;
		for (int i = 0; i < nums.size();i++)
		{
			//如果元素在已访问的集合中，则进行下一轮循环//
			if (visitedSet.find(nums[i])!=visitedSet.end())
			{
				continue;
			}

			count = 1;
			int left = nums[i];
			while(existedSet.find(--left)!=existedSet.end())
			{
				count++;
				visitedSet.insert(left);
			}
			int right = nums[i];
			while (existedSet.find(++right)!=existedSet.end())
			{
				count++;
				visitedSet.insert(right);
			}
			maxCount = max(maxCount, count);
		}
		return maxCount;
	}
private:
	inline int max(int a, int b)
	{
		return a > b ? a : b;
	}
};






int main()
{
	vector<int> nums = { 100, 200, 101, 2, 1, 3, 4 };
	Solution testCase;

	cout << testCase.longestConsecutive(nums) << endl;

	getchar();
	return 0;
}
