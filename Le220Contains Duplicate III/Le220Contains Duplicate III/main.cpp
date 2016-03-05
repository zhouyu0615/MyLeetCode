#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


//³¬Ê±//
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int len = nums.size();
		if (len <= 1 || k == 0||t<0) return false;
		
		for (int i = 0; i < len;i++)
		{
			int pos = Min(i + k+1, len);
			for (int j = i + 1; j < pos; j++)
			{
				if (abs(nums[i]-nums[j])<=t)
				{
					return true;
				}
			}
		}
		return false;
	}
private:
	int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};


class Solution2 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

		int len = nums.size();
		if (len <= 1 || k == 0||t<0) return false;

		multiset<long long> NumsSet;
		multiset<long long>::iterator pIter;

		for (int i = 0; i < len;i++)
		{
			if (NumsSet.size()>=k+1)
			{
				NumsSet.erase(NumsSet.find(nums[i-k-1]));
			}
			pIter=NumsSet.lower_bound(nums[i] - t);

			if (pIter!=NumsSet.end()&&abs(*pIter-nums[i])<=t)
			{
				return true;
			}

			NumsSet.insert(nums[i]);
		}

		return false;

	}
};


class Solution3 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		 
		int len = nums.size();
		if (len <= 1 || k == 0 || t < 0) return false;

		vector<myNum> myNums;
		myNums.assign(len, myNum());
		for (int i = 0; i < len;i++)
		{
			myNums[i].index = i;
			myNums[i].num = nums[i];
		}
		sort(myNums.begin(), myNums.end());

		for (int i = 0; i < len - 1;i++)
		{
			for (int j = i + 1; j < len;j++)
			{
				if (myNums[j].num - myNums[i].num <= t)
				{
					if (abs(myNums[j].index - myNums[i].index) <= k)
					{
						return true;
					}
				}
				else
				{
					break;
				}

			}
		}
		return false;

	};
	struct myNum
	{
		long num = 0;
		int index = 0;
		bool operator<(const myNum &rhs) const
		{
			return num < rhs.num;
		}
	}; 
	
};





int main()
{
	Solution3 testCase;
	vector<int > nums= {7,2,1};

	cout << testCase.containsNearbyAlmostDuplicate(nums,1,3)<<endl;

	getchar();
	return 0;
}
