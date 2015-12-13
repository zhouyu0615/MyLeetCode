#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {		
		size_t len = nums.size();
		vector<int>::iterator pI; ;
		size_t count = 1;
		if (len<=1)
		{
			return len;
		}
		for (pI = nums.begin()+1; pI  != nums.end();)
		{
			if (*pI==*(pI-1))
			{
				pI = nums.erase(pI);
			}
			else
			{
				++pI;
				count++;
			}
		}
		return count;
	}
};



int main()
{
	Solution test;
	vector<int> nums = { 1, 1,2,2,2, 3,3,3, 4 };

	cout << "result= " << test.removeDuplicates(nums);





	getchar();
	return 0;
}