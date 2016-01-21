#include <vector>


using namespace std;

/* Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		DfsAdd(root, 0);
	
		for (int i = 0; i < vAddSum.size();i++)
		{
			sum += vAddSum[i];
		}
		return sum;
	}
private:
	vector<int> vAddSum;
	void DfsAdd(TreeNode* TNode, int tempSum)
	{
		if (TNode==NULL)
		{
			return;
		}

		tempSum = tempSum*10+TNode->val;
		if (TNode->left==NULL&&TNode->right==NULL)
		{
			vAddSum.push_back(tempSum);
			return;
		}

		DfsAdd(TNode->left, tempSum);
		DfsAdd(TNode->right, tempSum);
		return;
	}

};