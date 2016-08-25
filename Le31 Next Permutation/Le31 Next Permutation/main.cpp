#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		int i=0;
		int j = 0;
		for (i = len - 2; (i >= 0)&&(nums[i]>=nums[i+1]); --i);

		if (i<0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		for (j = len - 1;nums[j]<=nums[i]; --j);
		Swap(nums[i], nums[j]);
		reverse(nums.begin()+i+1, nums.end());
		return;
	}


private:
	void Swap(int &a, int &b)
	{	
		int temp = a;
		a = b;
		b = temp;
	}
};





int main()
{

	Solution testCase;

	vector<int> nums = { 1, 2, 3, 5, 4 };
	
	testCase.nextPermutation(nums);

	//next_permutation(nums.begin(), nums.end());

	for (int i = 0; i < nums.size();i++)
	{
		cout << nums[i] << " ";
	}

	cout << endl;
	getchar();
	return 0;
}