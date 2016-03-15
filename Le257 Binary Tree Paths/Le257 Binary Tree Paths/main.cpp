#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root==NULL)
		{
			return result;
		}
		string str;
		stringstream stream;
		stream << (root->val);
		str = stream.str();
		if (root->left==NULL&&root->right==NULL)
		{
			result.push_back(str);
			return result;
		}
		Dfs(root->left, str);
		Dfs(root->right, str);
		return result;
	}
private:
	vector<string> result;
	void Dfs(TreeNode *TNode,string str)
	{
		if (TNode==NULL)
		{
			return ;
		}
		str.append("->");
		stringstream stream;
		stream << (TNode->val);
		str.append(stream.str());
		if (TNode->left==NULL&&TNode->right==NULL)
		{
			result.push_back(str);
			return;
		}
		Dfs(TNode->left, str);
		Dfs(TNode->right, str);
	}
};



int main()
{

	getchar();
	return 0;
}