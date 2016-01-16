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
	bool isValidBST(TreeNode* root) {

		return DfsCheck(root, LONG_MIN, LONG_MAX);
	}
private:
	bool DfsCheck(TreeNode* TNode, long leftVal, long rightVal)
	{
		if (TNode==NULL)
		{
			return true;
		}

		bool result = ((TNode->val > leftVal) && (TNode->val < rightVal));
		bool left = DfsCheck(TNode->left, leftVal, TNode->val);
		bool right = DfsCheck(TNode->right, TNode->val, rightVal);

		return result&&left&&right;
		
	}
};




int main()
{


	getchar();
	return 0;
}