#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
		{
			return 1;
		}

		int i = 0;
		while (i < len)
		{
			if (nums[i] == i)
			{
				i++;
			}
			else
			{
				if (nums[i] >= 0 &&nums[i]<len&&nums[i]!=nums[nums[i]])
				{
					int temp = nums[i];
					Swap(nums[i],nums[temp]);
					continue;						
				}
				else
				{
					i++;
				}
			}
		}

		for (int i = 1; i < len;i++)
		{
			if (nums[i]!=i)
			{
				return i;
			}
		}
		return nums[0] == len ? len + 1 : len;

	}
private:
	void Swap(int &a,int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	};
};

int main()
{
	Solution testCase;

	vector<int> nums = { 3, 4, 5, 6, 2, 1, 9 };

	cout << testCase.firstMissingPositive(nums) << endl;


	getchar();
	return 0;
}