#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		map<char, char> strMp;
		set<char> leftSet;
		stack<char> charstack;

		leftSet.insert('(');
		leftSet.insert('{');
		leftSet.insert('[');

		strMp['('] = ')';
		strMp['{'] = '}';
		strMp['['] = ']';

		size_t len = s.length();
		if (len % 2 != 0) //��������//
		{
			return false;
		}

		for (size_t i = 0; i < len; i++)
		{
			if (leftSet.count(s[i]) != 0) //�����Ž�ջ//
			{
				charstack.push(s[i]);
			}
			else //��������ջ��Ԫ�ؽ���ƥ��//
			{
				if (charstack.empty())
				{
					return false;
				}
				if (s[i] == strMp[charstack.top()])
				{
					charstack.pop();//����ջ��Ԫ��//
				}
				else
				{
					return false;
				}

			}
		}
		if (charstack.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};



class Solution2 {
public:
	bool isValid(string s) {
		
		stack<char> charstack;

		int len = s.length();
		if (len % 2 != 0) //��������//
		{
			return false;
		}

		for (size_t i = 0; i < len; i++)
		{
			if (s[i] == '(' || s[i] == '{'|| s[i]=='[') //�����Ž�ջ//
			{
				charstack.push(s[i]);
			}
			else //��������ջ��Ԫ�ؽ���ƥ��//
			{
				if (charstack.empty())
				{
					return false;
				}
				char temp = charstack.top();
				switch (s[i])
				{
				case '}':
						if ('{'==temp)
						{
							charstack.pop();
						}
						else
						{
							return false;
						}

					break;
				case ']':
					if ('[' == temp)
					{
						charstack.pop();
					}
					else
					{
						return false;
					}

					break;
				case ')':
					if ('(' == temp)
					{
						charstack.pop();
					}
					else
					{
						return false;
					}

					break;
				default:
					return false;
					break;
				}
			}
		}
		if (charstack.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};





int main()
{
	string str = "()";
	Solution test;


	cout << "result= " << test.isValid(str)<<endl;

	getchar();
	return 0;
}