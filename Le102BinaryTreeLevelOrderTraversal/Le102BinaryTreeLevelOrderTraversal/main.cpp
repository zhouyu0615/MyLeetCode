#include <iostream>
#include <vector>
#include <queue>


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
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>> result;
		queue<TreeNode*> BfsQueue;

		if (root == NULL) return result;

		vector<int> temp;

		BfsQueue.push(root);	
		TreeNode *pLevelFlag = new TreeNode(0);

		BfsQueue.push(pLevelFlag);

		while (BfsQueue.size()>1)
		{
			TreeNode *pNode = BfsQueue.front();
			BfsQueue.pop();
			if (pNode==pLevelFlag)
			{
				result.push_back(temp);
				temp.clear();
				BfsQueue.push(pLevelFlag);
			}
			else
			{
				temp.push_back(pNode->val);
				if (pNode->left!=NULL)
				{
					BfsQueue.push(pNode->left);
				}
				if (pNode->right!=NULL)
				{
					BfsQueue.push(pNode->right);
				}
			}		
		}
		result.push_back(temp);
		return result;
	}
};