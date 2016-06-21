#include <iostream>
#include <vector>

using namespace std;









class NumArray {
public:
	NumArray(vector<int> &nums) {

		len = nums.size();
		DpSum.assign(len + 1, 0);


		if (len == 0)
		{
			return;
		}
		DpSum[0] = 0;
		for (int i = 0; i < len; i++)
		{
			DpSum[i + 1] = DpSum[i] + nums[i];
		}

	}

	int sumRange(int i, int j) {
		return (DpSum[j + 1] - DpSum[i]);
	}

private:
	vector<int> DpSum;
	int len;
};




// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{

	vector<int> nums = { -2, 0, 3, -5, 2, -1 };

	NumArray numArry(nums);

	cout << numArry.sumRange(0, 0) << endl;
	cout << numArry.sumRange(2, 5) << endl;
	cout << numArry.sumRange(0, 5) << endl;
	getchar();
	return 0;
}