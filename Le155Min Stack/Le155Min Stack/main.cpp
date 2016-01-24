#include <iostream>
#include <vector>

using namespace std;


class MinStack {
public:
	void push(int x) {	
		DataStack.push_back(x);			
		if (DataStack[MinPos]>x)
		{
			MinPos = DataStack.size() - 1;
		}
	}

	void pop() {
		
		if (MinPos==(DataStack.size()-1))
		{
			DataStack.pop_back();
			MinPos = 0;
			for (int i = 0; i < DataStack.size();i++)
			{
				if (DataStack[i]<DataStack[MinPos])
				{
					MinPos = i;
				}
			}
		}
		else
		{
			DataStack.pop_back();
		}
		
	}

	int top() {	
		int len = DataStack.size() - 1;
		return DataStack[len];

	}

	int getMin() {

		return DataStack[MinPos];
	}

private:
	vector<int> DataStack;
	int MinPos = 0;;
};