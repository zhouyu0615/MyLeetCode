#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		long long nSize=1<<n;
		for (int i = 0; i < nSize;++i)
		{
			result.push_back(((i >> 1) ^ i));
		}
		return result;
	}
};


int main()
{

	getchar();
	return 0;
}