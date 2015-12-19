#include <iostream>


using namespace std;


class Solution {
public:
	double myPow(double x, int n) {

		int Signedflag = 0;
		if (n<0)
		{
			Signedflag =1 ;
			n = -n;
		}
	    

		if (n == 0||x==1) return 1;
		if (x==-1.0)
		{
			if (n%2==0)
			{
				return 1;
			}
			else
			{
				return -1;
			}

		}
		if (n==1)
		{
			if (Signedflag)
			{
				return 1/x;
			}
			return x;
		}


		if (n>=2)
		{
			if (n%2==0) //偶数倍
			{
				if (Signedflag) //n为负数
				{
					return 1/(myPow(pow2(x), n / 2));
				}
				else
				{
					return myPow(pow2(x), n / 2);
				}
				
			}
			else
			{
				if (Signedflag) //n为负数
				{
					return 1 / (x*myPow(pow2(x), n / 2));
				}
				else
				{
					return x*myPow(pow2(x), n / 2);
				}
			}
				
		}
	}

private:
	double pow2(double x)
	{
		return x*x;
	}
};



int main()
{
	Solution testCase;

	cout << testCase.myPow(-1, -21478);


	getchar();
	return 0;
}