#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	vector<int> countBits(int num) {
		for (int i = 0; i <= num;i++)
		{
			result.push_back(calBits(i));
		}
		return result;
	}
private:
	vector<int> result;
	int calBits(int target)
	{
		int count = 0;
		for (int i = 0; i < 32;i++)
		{
			if (target&(1<<i))
			{
				count++;
			}
		}
		return count;
	}
};



class Solution2 {
public:
	vector<int> countBits(int num) {
		vector<int> result;
		
		result.assign(num + 1, 0);
		if (num<1)
		{
			return result;
		}
		result[0] = 0;
		result[1] = 1;
		int powN = 0;
		int PreBase =2;
		for (int i = 2; i <= num;i++)
		{
			if (i>PreBase&&i<2*PreBase)
			{				
				result[i] = 1 + result[i - PreBase];
			}
			else if (i==PreBase)
			{
				result[i] = 1;
			}else if (i==2*PreBase)
			{
				result[i] = 1;
				PreBase = 2 * PreBase;
			}		
		}
		return result;
	}
};





int main()
{

	vector<int> result;
	Solution2 testCase;
	result = testCase.countBits(0);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}


	getchar();
	return 0;
}