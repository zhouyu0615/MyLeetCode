#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	bool canJump(vector<int>& nums) {

		int length = nums.size();
		int maxIndex = 0;//���ܴﵽ����������ֵ//
		int temp = 0;
		int index = 0;
		while (true)
		{
			temp = index + nums[index];
			maxIndex = (maxIndex < temp ? temp : maxIndex);
			if (maxIndex >= (length-1))
			{
				return true;
			}
			if (index<maxIndex)
			{
				index++;
			}
			else
			{
				return false;
			}
		}
	}
};


int main()
{




	getchar();
	return 0;
}

