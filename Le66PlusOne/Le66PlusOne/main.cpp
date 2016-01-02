#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res;
		int len = digits.size();

		digits[len - 1]++;
		for (int i = len - 1; i >0;i--)
		{
			if (digits[i]>9)//½øÎ»//
			{
				digits[i - 1]++;
				digits[i] = digits[i] % 10;
			}
			else
			{
				break;
			}
		}

		if (digits[0] > 9)
		{
			vector<int> res;
			res.push_back(1);
			digits[0] = digits[0] % 10;
			res.insert(res.end(),digits.begin(), digits.end());
			return res;
		}
		else
		{
			return digits;
		}
	}
};

int main()
{

	Solution testCase;
	vector<int> digits = { 8, 9, 9, 9 };

	vector<int> res;
	res = testCase.plusOne(digits);

	for (int i = 0; i < res.size();i++)
	{
		cout << res[i];
	}
	cout << endl;
	


	getchar();
	return 0;
}

