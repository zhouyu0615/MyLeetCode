#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int count[3] = {0};

		for (int i = 0; i < nums.size();i++)
		{
			switch (nums[i])
			{
			case 0:
				count[0]++;
				break;
			case 1:
				count[1]++;
				break;
			case 2:
				count[2]++;
				break;
			default:
				break;
			}
		}
		fill(nums.begin(), nums.begin() + count[0], 0);
		fill(nums.begin()+count[0], nums.begin() + count[0]+count[1], 1);
		fill(nums.begin() + count[0] + count[1], nums.begin() + count[0] + count[1]+count[2], 2);
	}
};



int main()
{





	getchar();
	return 0;
}



