#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	string largestNumber(vector<int>& nums) {

		vector<string> str_nums;
		for (int i = 0; i < nums.size();++i)
		{
			str_nums.push_back(to_string(nums[i]));
		}

		sort(str_nums.begin(), str_nums.end(), comp);

		string result;
		bool flag = false;

		for (int i = 0; i < str_nums.size();++i)
		{
			if (str_nums[i]!="0")
			{
				result += str_nums[i];
				flag = true;
			}
			else if (flag)
			{
				result += str_nums[i];
			}
		}

		if (!flag)//ȫ0
		{
			result.push_back('0');
		}

		return result;

	}

private:
	bool static comp(const string& str1, const string& str2)
	{
		return (str1 + str2) > (str2 + str1);
	}
};

int main()
{

	vector<int> nums = { 0,0,0,0,0,0};

	Solution testCase;

	cout << testCase.largestNumber(nums) << endl;

	getchar();
	return 0;
}