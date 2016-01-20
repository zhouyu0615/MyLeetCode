#include <iostream>
#include <vector>

using namespace std;


/*Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		target = sum;
		DfsPathSum(root, 0);
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> temp;
	int target = 0;

	void DfsPathSum(TreeNode* TNode,int sum)
	{
		if (TNode == NULL)
		{
			return;
		}

		sum = sum + TNode->val;
		temp.push_back(TNode->val);
		if (sum == target&&TNode->left==NULL&&TNode->right==NULL)
		{
			result.push_back(temp);
			temp.pop_back();
			return;
		}
		DfsPathSum(TNode->left, sum);
		DfsPathSum(TNode->right, sum);
		temp.pop_back();
		sum = sum - TNode->val;
		return;
	}

};

int main()
{

	Solution testCase;
	TreeNode *root = new TreeNode(0);
	TreeNode *left = new TreeNode(1);
	TreeNode *right = new TreeNode(1);
	root->left = left;
	root->right = right;

	vector<vector<int>> result;

	result = testCase.pathSum(root,1);

	for each (vector<int> var in result)
	{
		for each (int var1 in var)
		{
			cout << var1 << " ";
		}
		cout << endl;
	}



	getchar();
	return 0;

}