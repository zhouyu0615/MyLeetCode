#include <iostream>
#include <vector>



using namespace std;


/**
* Definition for a binary tree node.*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		Preoredr(root);

		return result;
	}
private:
	vector<int> result;
	void Preoredr(TreeNode* TNode)
	{		
		if (TNode==NULL)
		{
			return;
		}
		result.push_back(TNode->val);
		Preoredr(TNode->left);
		Preoredr(TNode->right);
	}
};



int main()
{



	getchar();
	return 0;
}
