#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {

		int count = 0;
		while (m!=n)
		{
			m = m >> 1;
			n = n >> 1;
			count++;
		}
		return m << count;
	}
};


int main()
{
	Solution testCase;

	cout << testCase.rangeBitwiseAnd(5, 7)<<endl;
	getchar();
	return 0;
}