#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (n<=k)
		{
			return m_result;
		}
		m_len = k;	
		DfsFind(1, n);
		return m_result;
	}
private:
	vector<vector<int>> m_result;
	vector<int> temp;
	int m_len = 0;
	void DfsFind(int start,int res)
	{
		if (temp.size()==m_len&&res==0)
		{
			m_result.push_back(temp);		
			return;
		}

		if (temp.size()>=m_len||res<start)
		{
			return;
		}
		for (int i = start; i <= 9;++i)
		{
			if (res < i)
			{
				break;
			}
			temp.push_back(i);
			DfsFind(i + 1, res - i);
			temp.pop_back();
		}
	}
};

int main()
{
	Solution testCase;

	vector<vector<int>> Result;

	Result = testCase.combinationSum3(3, 9);

	for (int i = 0; i < Result.size();++i)
	{
		for (int j = 0; j < Result[0].size();++j)
		{
			cout << Result[i][j] << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}