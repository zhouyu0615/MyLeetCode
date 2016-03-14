#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		mainStack.push(x);
	}

	// Removes the element from in front of queue.//
	void pop(void) {
		while (mainStack.size()>1)
		{
			tempStack.push(mainStack.top());
			mainStack.pop();
		}
		if (mainStack.size()==1)
		{
			mainStack.pop();
		}
		while (!tempStack.empty())
		{
			mainStack.push(tempStack.top());
			tempStack.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		int x = 0;
		while (!mainStack.empty())
		{
			x = mainStack.top();
			tempStack.push(x);
			mainStack.pop();
		}
		while (!tempStack.empty())
		{
			mainStack.push(tempStack.top());
			tempStack.pop();
		}
		return x;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return mainStack.empty();
	}
private:
	stack<int>  mainStack;
	stack<int>  tempStack;
};



int main()
{
	Queue myQueue;
	vector<int> nums = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < nums.size();i++)
	{
		myQueue.push(nums[i]);
	}
	
	cout << myQueue.peek()<<endl;

	getchar();
	return 0;
}
