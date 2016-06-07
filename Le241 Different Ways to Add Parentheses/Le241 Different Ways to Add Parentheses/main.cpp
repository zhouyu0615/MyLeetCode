#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;

		int len = input.size();
		for (int i = 0; i <len;i++)
		{	
			if (input[i]=='+'||input[i]=='-'||input[i]=='*')
			{
				string str1 = input.substr(0, i);
				string str2 = input.substr(i + 1);
				vector<int> leftResult = diffWaysToCompute(input.substr(0,i));
				vector<int> rightResult = diffWaysToCompute(input.substr(i + 1));
	
				for (int j = 0; j < leftResult.size();j++)
				{
					for (int k = 0; k < rightResult.size();k++)
					{

						if (input[i]=='+')
						{
							result.push_back(leftResult[j] + rightResult[k]);
						}else if (input[i]=='-')
						{
							result.push_back(leftResult[j] - rightResult[k]);
						}
						else if (input[i]=='*')
						{
							result.push_back(leftResult[j] * rightResult[k]);
						}
					}
				}
			}
		}
		if (result.empty())
		{
			result.push_back(atoi(input.c_str()));
		}
		return result;
	}
};



int main()
{

	Solution testCase;
	string str = "2*3-4*5";
	//string str = "2 - 1 - 1";
	vector<int> result;
	result=testCase.diffWaysToCompute(str);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}

	getchar();
	return 0;
}
