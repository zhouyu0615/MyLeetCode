#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		int sumLen = m + n - 1;

		nums1.resize(m + n);

		int pos1 = m - 1;
		int pos2 = n - 1;
		for (int i = sumLen; i >= 0; i--)
		{
			if (pos1 < 0)
			{
				copy(nums2.begin(), nums2.begin() + pos2+1, nums1.begin());
				return;
			}
			if (pos2 < 0)
			{
				return;
			}
			if (nums1[pos1] > nums2[pos2])
			{
				nums1[i] = nums1[pos1];
				pos1--;
			}
			else
			{
				nums1[i] = nums2[pos2];
				pos2--;
			}

		}
	}
};




int main()
{

	vector<int> Nums1 = { 0 };
	vector<int> Nums2 = { 1 };

	Solution testCase;

	testCase.merge(Nums1, 0, Nums2, 1);

	for each (int var in Nums1)
	{
		cout << var << " ";
	}

	getchar();
	return 0;
}




