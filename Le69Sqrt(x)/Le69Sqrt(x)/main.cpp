#include <iostream>
#include <math.h>


using namespace std;


class Solution {
public:
	int mySqrt(int x) {
		if (x==0)
		{
			return 0;
		}
		double pre=0;
		double cur=1;

		while (abs(cur-pre)>0.000001)
		{
			pre = cur;
			cur = pre / 2 + x / (2 * pre);//Å£¶Ùµü´ú·¨£¬xi+1= (xi + n/xi) / 2
		}
		return int(cur);
	}
};



int main()
{

	Solution testCase;
	
	cout << testCase.mySqrt(15);

	getchar();
	return 0;
}

