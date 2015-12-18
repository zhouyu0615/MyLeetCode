#include <iostream>
#include <vector>
#include <string>
#include <CString>

using namespace std;





class Solution1 {

public:
	vector<string> addOperators(string num, int target) {
		m_StrNum = num;
		m_target = target;

		length = num.length();

		if (length >= 1)
		{
			string str="";
			DfsCalc(0,0,0,str);
		}
		return strRes;
	}
private:
	vector<string> strRes;
	string m_StrNum;

	int m_target = 0;
	int length = 0;
	void DfsCalc(double preNum,double sum, int startPos, string str)
	{
		if (sum == m_target&&startPos == length)
		{
			strRes.push_back(str);
			return;
		}
		else
		{	

			long long currentNum = 0;
			for (int i = startPos; i < length; i++)
			{
				if (m_StrNum[startPos]=='0'&&(i!=startPos)) //起始位置上数字为0
				{
					break;
				}
				
				string strTmp;
				strTmp=strTmp+m_StrNum[i];// m_StrNum.substr(startPos, (i-startPos+1));
				//double currentNum = getCurNum(strTmp);
				currentNum = currentNum * 10 + (m_StrNum[i] - '0');

				if (startPos==0)
				{
					DfsCalc(currentNum, currentNum, i+1, strTmp);
				}
				else
				{
					DfsCalc(currentNum, sum + currentNum, i + 1, str + "+" + strTmp);
					DfsCalc(-currentNum, sum - currentNum, i + 1, str + "-" + strTmp);
					DfsCalc(preNum*currentNum, (sum - preNum) + preNum * currentNum, i + 1, str + "*" + strTmp);
				}
			}
		}
	}


	double getCurNum(const string &str)
	{
		double result = 0;
		for (int i = 0; i < str.length();i++)
		{
			if (str[i]>='0'&&(str[i]<='9'))
			{
				result = result * 10 + (str[i] - '0');
			}			
		}
		return result;

	}

};


int main()
{
	Solution1 testCase;
	string num = "123";

	double target = 6;

	vector<string> strRes;

	strRes = testCase.addOperators(num, target);

	for (int i = 0; i < strRes.size();i++)
	{
		cout << strRes[i] << endl;
	}


	getchar();
	return 0;
}