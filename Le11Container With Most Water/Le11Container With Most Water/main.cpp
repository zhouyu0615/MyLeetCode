#include<iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxArea = 0;
		int left = 0;
		int right = height.size() - 1;

		int Area;
		while (left<right)
		{
			Area = (right - left)*Min(height[left], height[right]);
			maxArea = Max(maxArea, Area);

			if (height[left]>height[right])
			{
				right--;
			}
			else
			{
				left++;
			}
		}
		return maxArea;
	}
private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};


int main()
{

	vector<int> nums = { 3, 5, 2, 8, 4 };
	
	Solution teseCase;
	
	cout << teseCase.maxArea(nums)<<endl;

	getchar();
	return 0;
}