#include <iostream>


using namespace std;

class Solution {
public:
	unsigned int reverseBits(unsigned int n) {

		unsigned int res=0;
		for (int i = 0; i < 32;i++)
		{
			if (n&(1<<i))
			{
				res |= (1 << (31-i));
			}
		}

		return res;
	}
};

int main()
{
	Solution testCase;

	cout << testCase.reverseBits(43261596);

	getchar();
	return 0;
}