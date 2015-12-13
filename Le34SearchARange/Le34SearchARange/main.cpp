#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;

		int startPos = -1;
		int endPos = -1;

		int length = nums.size();
		result.push_back(startPos);
		result.push_back(endPos);
		if (length == 0)
		{
			return result;
		}
		int low = 0;
		int high = nums.size();
		int mid = (low + high) / 2;
		while (low<high)
		{
			if (nums[mid] == target)
			{
				startPos = mid;
				endPos = mid;
				while (startPos >= 0 && nums[startPos] == target)
				{
					startPos--;
				}
				while (endPos < length&&nums[endPos] == target)
				{
					endPos++;
				}
				result.clear();
				result.push_back(startPos + 1);
				result.push_back(endPos - 1);
				break;
			}


			if (nums[mid]<target)
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else
			{
				high = mid - 1;
				mid = (low + high) / 2;
			}		
		}
		return result;
	}
};


int main()
{
	Solution testCase;
	vector<int> nums = { 5, 7, 7, 8, 8, 8,10 };
	//vector<int> nums = { 1};
	vector<int> result = testCase.searchRange(nums, 8);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i]<<" ";
	}
	cout << endl;

	getchar();
	return 0;
}