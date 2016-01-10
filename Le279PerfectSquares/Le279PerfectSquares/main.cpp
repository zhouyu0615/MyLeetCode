#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	int numSquares(int n) {

		vector<int> DpSquares;
		DpSquares.assign(n + 1, INT_MAX);

		for (int i = 0; i*i <=n;i++)
		{
			DpSquares[i*i] = 1;
		}

		if (DpSquares[n]==1)
		{
			return DpSquares[n];
		}


		for (int a = 0; a <=n;a++)
		{
			for (int b = 0; (a + b*b )<= n;b++)
			{
				DpSquares[a + b*b] = Min(DpSquares[a] + 1, DpSquares[a + b*b]);
			}
		}

		return DpSquares[n];
	}

private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};



class Solution2 {
public:
	int numSquares(int n) {

		vector<int> DpSquares;
		DpSquares.assign(n + 1, INT_MAX);

		

		for (int a = 0; a <= n; a++)
		{
			DpSquares[a] = a;
			for (int b = (int)sqrt(a); b >= 1 && DpSquares[a] > 1; b--)
			{
				DpSquares[a] = Min(DpSquares[a - b*b] + 1, DpSquares[a]);
			}
		}

		return DpSquares[n];
	}

private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};




int main()
{
	Solution testCase;

	int num = 0;
	while (cin>>num)
	{
		cout << testCase.numSquares(num) << endl;
	}
	

	getchar();
	return 0;
}

