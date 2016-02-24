#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		
		if (k>len)
		{
			k = k%len;
		}
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };

	Solution testCase;
	
	testCase.rotate(nums,3);
	for (int i = 0; i < nums.size();i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}