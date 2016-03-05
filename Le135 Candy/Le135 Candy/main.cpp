#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> MinCandy;
		int len = ratings.size();
		MinCandy.assign(len, 1);
		int candy = 1;
		for (int i = 1; i < len;i++)
		{
			if (ratings[i]>ratings[i-1])
			{
				MinCandy[i] = Max(++candy, MinCandy[i]);
			}
			else
			{
				candy = 1;
			}
		}
		candy = 1;
		for (int i = len - 2; i >= 0;i--)
		{
			if (ratings[i]>ratings[i+1])
			{
				MinCandy[i] = Max(++candy, MinCandy[i]);
			}
			else
			{
				candy = 1;
			}
		}
		int result = 0;
		for (int i = 0; i < len;i++)
		{
			result += MinCandy[i];
		}
		return result;
	}
private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{

	vector<int> rating = { 4,2,3,4,1 };
	Solution testCase;

	cout << testCase.candy(rating) << endl;


	getchar();
	return 0;
}