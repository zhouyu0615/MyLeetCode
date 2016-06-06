#include <iostream>
#include <string>
#include <stack>

using namespace std;



class Solution {
public:
	void reverseWords(string &s) {
		stack<string> wordsStack;
		int wordStartPos=0;
		int len = s.length();
		for (int i = 0; i < len;i++)
		{
			if (i==0&&s[i]==' ') continue;
			if ((i>=1)&&(s[i]==' ')&&(s[i-1]==' ')) continue;
			if ((i>=1)&&(s[i]!=' ')&&(s[i-1]==' '))
			{
				wordStartPos = i;
			}
			if (((s[i]==' ')||i==(len-1))&&(i>=wordStartPos))
			{
				if (i==(len-1))
				{
					i++;
				}
				string str = s.substr(wordStartPos, i - wordStartPos);
				wordsStack.push(str);
			}
		}
		string temp;
		int numsOfWords = wordsStack.size();
		for (int i = 0; i <numsOfWords;i++)
		{
			temp += wordsStack.top();
			if (i<numsOfWords - 1)
			{
				temp += " ";
			}
			wordsStack.pop();
		}	
		s.clear();
		s = temp;
	}
};



class Solution2 {
public:
	void reverseWords(string &s)
	{
		stack<char> word;
		stack<char> sentence;
		int i = 0;

		while (i <= s.size())
		{
			if (i == s.size() || s[i] == ' ')
			{
				if (!word.empty())
				{
					if (!sentence.empty())
					{
						sentence.push(' ');
					}
					while (!word.empty())
					{
						sentence.push(word.top());
						word.pop();
					}
				}
			}
			else
			{
				word.push(s[i]);
			}
			i++;
		};

		s.clear();
		while (!sentence.empty()){
			s.push_back(sentence.top());
			sentence.pop();
		};
	}
};


int main()
{

	string str = "The sky is blue";
	//string str = "      ";
	//string str = "a";
	//string str = "1   ";
	Solution2 testCase;

	testCase.reverseWords(str);

	cout << str << endl;	


	getchar();
	return 0;
}