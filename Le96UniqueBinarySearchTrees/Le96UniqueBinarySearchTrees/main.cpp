#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int numTrees(int n) {
		vector<int> DpNums;
		DpNums.assign(n + 1, 0);
		
		DpNums[0] = 1;

		for (int i = 1; i <=n;i++)//可切换根节点的个数//
		{
			if (i<3)
			{
				DpNums[i] = i;
			}
			else
			{
				for (int j = 0; j < i; j++) //左边节点数//
				{
					DpNums[i] = DpNums[i] + DpNums[i - j - 1] * DpNums[j];
				}
			}


		}
		return DpNums[n];
	}
};


int main()
{
	Solution testCase;

	int n = 0;
	while (cin>>n)
	{
		cout << testCase.numTrees(n) << endl;
	}

	getchar();
	return 0;
}





