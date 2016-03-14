#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		mainQueue.push(x);
	}

	// Removes the element on top of the stack.//
	void pop() {
		while (mainQueue.size()>1)
		{		
			tempQueue.push(mainQueue.front());
			mainQueue.pop();
		}	
		if (mainQueue.size()==1)
		{
			mainQueue.pop();
		}
		while (!tempQueue.empty())
		{
			mainQueue.push(tempQueue.front());
			tempQueue.pop();
		}
		return;
	}

	// Get the top element.
	int top() {
		int x=0;
		while (!mainQueue.empty())
		{
		    x = mainQueue.front();
			tempQueue.push(x);
			mainQueue.pop();
		}
		while (!tempQueue.empty())
		{
			mainQueue.push(tempQueue.front());
			tempQueue.pop();
		}
		return x;
	}

	// Return whether the stack is empty.
	bool empty() {
		return mainQueue.empty();
	}

private:
	queue<int> mainQueue;
	queue<int> tempQueue;

};


int main()
{
	Stack mystack;
	vector<int> nums = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < nums.size();i++)
	{
		mystack.push(nums[i]);
	}
	mystack.pop();
	cout<<mystack.top()<<endl;

	getchar();
	return 0;
}