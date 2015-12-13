#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {

		size_t goalLen = haystack.length();
		size_t len = needle.length();

		if (len==0)
		{
			return 0;
		}
		char *p = (char *)haystack.data();
		for (size_t i = 0; i < goalLen; )
		{
			if (strncmp(p,needle.data(),len)==0)
			{
				return i;
			}
			i++;
			p++;
		}
		return -1;
	}
};



class Base
{
public:
	Base()
	{
	}

	~Base()
	{
	}

	void showMe()
	{
		cout << "Base" << endl;
	}

	virtual void show()
	{
		cout << "virtual base" << endl;
	}

private:

};

class Derived:public Base
{
public:
	Derived(){}
	~Derived(){}

	void showMe()
	{
		cout << "Derived" << endl;
	}

	virtual void show()
	{
		cout << "virtual Derived" << endl;
	}

private:

};





int main()
{

	Solution test;
	string str1="abcdadf", str2="ad";

	cout << "result= " << test.strStr(str1, str2)<<endl;

	
	Base base;
	base.showMe();
	base.show();

	Derived der;
	der.showMe();
	der.show();

	Base *p = new Derived();
	p->show();
	p->showMe();

	getchar();
	return 0;
}