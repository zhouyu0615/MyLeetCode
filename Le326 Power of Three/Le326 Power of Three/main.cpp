#include <iostream>
#include <math.h>


using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) 
	{
		if (n <= 0) return false;
		if (n == 1) return true;

		while (n>1)
		{
		   if (n%3==0)
		   {
			   n = n / 3;
		   }
		   else
		   {
			   return false;
		   }
		}
		return true;

	}
};



class Solution2 {
public:
	bool isPowerOfThree(int n) {
		int t = pow(3,(int)(log(INT_MAX) / log(3)));
		return n > 0 && (t%n==0); 
	}
};


int main()
{
	Solution2 testCase;

	cout << testCase.isPowerOfThree(26) << endl;

	getchar();
	return 0;
}