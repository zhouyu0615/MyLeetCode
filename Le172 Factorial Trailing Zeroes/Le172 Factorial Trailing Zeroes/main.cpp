#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {

		int count = 0;
		while (n>0)
		{
			count += n / 5;
			n = n / 5;
		}
		return count;
	}
};


int main()
{
	Solution testCase;

	cout << testCase.trailingZeroes(10);

	getchar();
	return 0;
}