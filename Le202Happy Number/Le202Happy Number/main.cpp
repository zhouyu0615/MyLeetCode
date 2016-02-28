#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> historySet;

		int temp = 0;
		temp = n;
		while (temp!=1)
		{
			temp = getResult(temp);
			if (historySet.find(temp)!=historySet.end())
			{
				return false;
			}
			historySet.insert(temp);
		}
		return true;

	}
private:
	int getResult(int n)
	{
		int result = 0;
		int temp = 0;
		while (n!=0)
		{
			temp = n % 10;
			n = n / 10;
			result += temp*temp;
		}
		return result;
	}
};


int main()
{

	Solution testCase;

	cout << testCase.isHappy(37)<<endl;

	getchar();
	return 0;
}