#include <iostream>
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
	vector<TreeNode*> generateTrees(int n) {
		if (n==0)
		{
			vector<TreeNode*> temp;
			return temp ;
		}
		return CreateTrees(1, n);
	}

private:
	
	vector<TreeNode*> CreateTrees(int start, int end)
	{
		vector<TreeNode*> results;
		if (start>end)
		{
			results.push_back(NULL);
			return results;
		}


		for (int k = start; k <= end;k++)
		{
			vector<TreeNode*> left = CreateTrees(start, k - 1);
			vector<TreeNode*>  right = CreateTrees(k + 1, end);
			for (int i = 0; i < left.size(); i++)
			{
				for (int j = 0; j < right.size();j++)
				{
					TreeNode* root = new TreeNode(k);
					root->left = left[i];
					root->right = right[j];
					results.push_back(root);	
				}
			}
		}
		return results;
	}
};



