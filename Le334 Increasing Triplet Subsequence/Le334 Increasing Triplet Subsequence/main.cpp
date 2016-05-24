#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size()<=2)
		{
			return false;
		}
		int minVal = nums[0];//保存当前位置为止最小的值
		int midVal = 0x7FFFFFFF;

		for (int i = 1; i < nums.size();i++)
		{
			if (nums[i]<minVal)
			{
				minVal = nums[i];
			}
			else if (nums[i]>minVal&&nums[i]<midVal)
			{
				midVal = nums[i];
			}
			else if (nums[i]>midVal&&midVal>minVal)
			{
				return true;
			}
			
		}
		return false;
	}
};



int main()
{
	vector<int> nums = {1,2,3,4,5};

	Solution testCase;
	cout<<testCase.increasingTriplet(nums)<<endl;

	getchar();
	return 0;
}