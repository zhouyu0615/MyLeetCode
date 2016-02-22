#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.size() != cost.size() || gas.size() == 0 || cost.size() == 0)
		{
			return -1;
		}

		int total = 0, sum = 0, start = 0;
		int diff = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			diff = gas[i] - cost[i];
			total += diff;

			if (sum < 0)//油箱为空，从下一站点起步尝试
			{
				sum = diff;
				start = i;
			}
			else
			{
				sum += diff;
			}
		}
		return total < 0 ? -1 : start;
	}
};



int main()
{


	getchar();
	return 0;
}