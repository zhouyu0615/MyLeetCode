#include <iostream>


using namespace std;



class Solution {
public:
	int reverse(int x) {
		if (x==0)
		{
			return 0;
		}

		long long result = 0;
		while (x % 10 == 0)
		{
			x = x / 10;
		} 

		while (x)
		{
			result = result * 10 + x%10;
			x = x / 10;

			if (result>INT_MAX||result<INT_MIN)
			{
				return 0;
			}

		}
		return result;
	}
};




int main()
{


	Solution test;

	cout << "Result=" << test.reverse(901000) << endl;

	getchar();


	return 0;
}