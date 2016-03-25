#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_map<int,int> numMap;
		for (int i = 0; i < nums.size();++i)
		{
			numMap[nums[i]]++;
		}

		vector<int> result;
		unordered_map<int, int>::iterator pI;
		for (pI = numMap.begin(); pI != numMap.end();++pI)
		{
			if (pI->second==1)
			{
				result.push_back(pI->first);
			}
		}
		return result;
	}
};


class Solution2 {
public:
	vector<int> singleNumber(vector<int>& nums) {

		int xorVal;
		int len = nums.size();
		for (int i = 0; i < len;++i)
		{
			xorVal ^= nums[i];
		}

		int firstBit1=0;//从低到高位，找到xorVal中第一个为1的位
		for (int i = 0; i <= 31;i++)
		{	
			//long long temp = (xorVal & (1 << i)) >> i;
			int temp = ((xorVal >> i) & 0x01);
			if (temp)
			{
				firstBit1 = i;
				break;
			}
		}


		int num1 = 0;
		int num2 = 0;
		for (int i = 0; i < len;++i)
		{
			//long long k = (nums[i] & ( 1 << firstBit1)) >>  firstBit1;
			long k = (nums[i] >> firstBit1) & 1;
			if (k) //两个数字只出现一次的数字，必有这个位存在区别//
			{
				num1 ^= nums[i];
			}
			else
			{
				num2 ^= nums[i];
			}
		}

		vector<int> result = { num1, num2 };
		return result;

	}
};




int main()
{

	getchar();
	return 0;
}


