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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size()==0||postorder.size()==0||inorder.size()!=postorder.size())
		{
			return NULL;
		}

		return Construct(inorder, postorder, 0, postorder.size() - 1, postorder.size());

	}
private:
	TreeNode* Construct(vector<int>& inorder, vector<int>& postorder, 
		int startIn, int startPost, int len)
	{
		if (len==0)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder[startPost]);

		int index;
		for (index = startIn; inorder[index] != postorder[startPost]; index++);
	
		
		int leftLen = index - startIn;
		int rightLen = len - leftLen-1;
		root->left = Construct(inorder, postorder, startIn,startPost-rightLen-1, leftLen);
		root->right = Construct(inorder, postorder, index + 1, startPost - 1, rightLen);
		return root;
	}
};



int main()
{

	vector<int> inorder = {4,2,5,1,6,3,7};
	vector<int> Postorder = { 4, 5, 2, 6, 7, 3, 1 };

	Solution testCase;
	TreeNode* root = testCase.buildTree(inorder, Postorder);

	getchar();
	return 0;
}