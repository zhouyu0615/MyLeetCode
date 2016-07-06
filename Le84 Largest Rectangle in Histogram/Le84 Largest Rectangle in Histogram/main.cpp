#include <iostream>
#include <vector>
#include <stack>



using namespace std;


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {

		int len = heights.size();
		int result = 0;
		stack<int> st;

		for (int i = 0; i < len;i++)
		{

			while (!st.empty() && heights[st.top()] >= heights[i]) // ��ջ���ߣ���ջ����Ԫ�ص��ұ߽�ȷ������ջ
			{
				int h = heights[st.top()];
				st.pop();
				result = Max(result, (i - 1 - (st.empty() ? (-1) : st.top()))*h);
			}
			st.push(i);
		}

		while (!st.empty())
		{
			int h = heights[st.top()];
			st.pop();
			result = Max(result, (len - 1 - (st.empty() ? (-1) : st.top()))*h);
		}
		return result;
	}
private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{

	getchar();
	return 0;
}