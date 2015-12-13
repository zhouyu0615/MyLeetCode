#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<vector<int>> result;
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		if (nums.size()<4)
		{
			return result;
		}

		sort(nums.begin(), nums.end());

		int len = nums.size();

		int sum = 0;

		vector<int> tempV(4, 0);

		for (size_t i = 0; i < len - 2;i++)
		{

			for (size_t j = i+1; j < len - 2;j++)
			{
				int low = j + 1;
				int high = len - 1;

				while (low < high)
				{   
					sum =nums[i]+nums[j] + nums[low] + nums[high]-target;
					if (sum==0)
					{
						tempV[0] = nums[i];
						tempV[1] = nums[j];
						tempV[2] = nums[low];
						tempV[3] = nums[high];						
						result.push_back(tempV);

						while (i<(len-2)&&nums[i]==nums[i+1])
						{
							i++;
						}

						while (j<(len-2)&&nums[j]==nums[j+1])
						{
							j++;
						}
						while (low<(len-1)&&nums[low] == nums[low + 1])
						{
							low++;
						}
						while ((high>1)&&nums[high] == nums[high - 1])
						{
							high--;
						}

						low++;
						high--;

					}
					else if (sum<0)
					{
						low++;
					}
					else
					{
						high--;
					}
				}
			}
			
		}
		return result;
	}


};




int main()
{

	Solution test;
	vector<int> nums = { -1, 0, -5, -2, -2, -4, 0, 1, -2};

	vector<vector<int>>::iterator pIter;
	vector<int>::iterator pI;
	vector<vector<int>> result;
	result = test.fourSum(nums,-9);



	for (pIter = result.begin(); pIter != result.end(); ++pIter)
	{
		for (pI = pIter->begin(); pI != pIter->end(); ++pI)
		{
			cout << *pI << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;

}





