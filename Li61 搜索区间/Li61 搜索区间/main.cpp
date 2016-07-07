#include <iostream>
#include <vector>

using namespace std;

class Solution {
	/**
	*@param A : an integer sorted array
	*@param target :  an integer to be inserted
	*return : a list of length 2, [index1, index2]
	*/
public:
	vector<int> searchRange(vector<int> &A, int target) {
		// write your code here
		vector<int> result = { -1, -1 };
		int pos = binSearch(A, target);
		if (pos!=-1)
		{
			int left = pos;
			while (left>=0&&A[left] == target){ left--; };
			result[0] = left + 1;

			int right = pos;
			while (right<A.size()&&A[right]==target)
			{
				right++;
			}
			result[1] = right-1;
		}
		return result;
	}
private:
	int binSearch(vector<int> &Nums, int target)
	{
		int left = 0;
		int right = Nums.size() - 1;

		int mid = 0;
		while (left<=right)
		{
			mid = (left + right) / 2;
			if (Nums[mid]==target)
			{
				return mid;
			}else if (Nums[mid]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;
	}
};

int main()
{

	vector<int> nums = { 5, 7, 7, 8, 8, 10 };

	Solution testCase;
	vector<int> result = testCase.searchRange(nums, 10);

	cout << result[0] << " " << result[1] << endl;

	getchar();
	return 0;
}