#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int addDigits(int num) {
		int sum=0;
		int temp = 0;

		if (num<10)
		{
			return num;
		}
		while (num>=10)
		{
			while (num)
			{
				temp = num % 10;
				sum += temp;
				num = (int)num / 10;
			}

			if (sum>=10)
			{
				num = sum;
				sum = 0;
			}
		}
		return sum;
	}
};


class Solution3 {
public:
	int addDigits(int num) 
	{
		int sum = 0;
		while (num>0)
		{
			sum += num % 10;
			if (sum>=10)
			{
				sum = sum % 10 + sum / 10;
			}
			num = num / 10;

		}

		return sum;	
	}
	
};



class Solution2 {
public:
	int addDigits(int num)
	{

		if (num==0)
		{
			return 0;
		}
		else
		{
			int temp = num % 9;
			return temp == 0 ? 9 : temp;
		}

	
	}

};





int main()
{

	Solution3 test;
	cout<<"Result= "<<test.addDigits(38)<<endl;

	getchar();
	return 0;
}

