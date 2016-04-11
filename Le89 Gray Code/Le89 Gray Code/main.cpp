#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		long long nSize=1<<n;
		for (int i = 0; i < nSize;++i)
		{
			result.push_back(((i >> 1) ^ i));
		}
		return result;
	}
};



class Solution2 {
public:
	vector<string> grayCode(int n) {
		vector<string> result;
		long long nSize = 1 << n;
		for (int i = 0; i < nSize; ++i)
		{
			result.push_back(toBinString(n,((i >> 1) ^ i)));
		}
		return result;
	}

	string toBinString(int n, int val)
	{
		stringstream ss;
		string str;
		for (int i = n-1; i>=0;i--)
		{
			ss << ((val & (1<<i))>>i);			
		}
		ss >> str;
		return str;
	}
};



class Solution3 {
public:
	vector<string> grayCode(int n) {
		vector<string> result;
		
		int len = pow(2, n);

		result.assign(len, "");

		if (n==1)
		{
			result[0] = "0";
			result[1] = "1";
			return result;
		}

		vector<string> temp = grayCode(n - 1);

		for (int i = 0; i < temp.size();i++)
		{
			result[i] = "0" + temp[i];
			result[len - 1 - i] = "1" + temp[i];
		}

		return result;
	}	
};





int main()
{
	Solution3 testCase;
	vector<string> result;
	result=testCase.grayCode(2);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}


	getchar();
	return 0;
}