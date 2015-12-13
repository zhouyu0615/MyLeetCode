#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;






class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int sum = nums[0] + nums[1] + nums[2];
		int low, high;

		int len = nums.size();
		sort(nums.begin(), nums.end());
		int result=sum;

		int minValue=abs(sum-target);
		for (size_t i = 0; i < len - 2;i++)
		 {
			 low = i + 1;
			 high = len - 1;

			 while (low<high)
			 {
				 sum = nums[i] + nums[low] + nums[high];
				 if (sum==target)
				 {
					 return target;
				 }else if (sum<target)
				 {
					 low++;
				 }
				 else
				 {
					 high--;
				 }
				 int temp = abs(sum - target);
				 if (temp < minValue)
				 {
					 minValue = temp;
					 result = sum;
				 }
			 }
		 }
		return result;	
	}


};


int main()
{
	Solution test;
	vector<int> nums = { 1,1,1,0 };

	cout << "result=" << test.threeSumClosest(nums, -100);



	getchar();
	return 0;
}


