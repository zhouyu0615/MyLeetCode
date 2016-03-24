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


/*
class Solution {
public:
	int rob(TreeNode* root) {

		if (root==NULL)
		{
			return 0;
		}
		queue<TreeNode*> qTNodes;
		vector<int> vNodeNums;
		int levelSum=0;
	
		TreeNode* Tnode = root;
		TreeNode* LevelFlag = new TreeNode(0);	
		qTNodes.push(root);
		qTNodes.push(LevelFlag);
		TreeNode* TempNode;
		while ( !qTNodes.empty())
		{
			TempNode = qTNodes.front();
			qTNodes.pop();
	
			if (TempNode == LevelFlag)
			{
				vNodeNums.push_back(levelSum);
				levelSum = 0;
				if (!qTNodes.empty())
				{
					qTNodes.push(LevelFlag);
				}			
				continue;
			}
			else
			{
				levelSum += TempNode->val;
				if (TempNode->left != NULL)
				{
					qTNodes.push(TempNode->left);
				}
				if (TempNode->right != NULL)
				{
					qTNodes.push(TempNode->right);
				}
			}			
		}//end of while

		int len = vNodeNums.size();
		vector<int> Dp;//dp[i]表示取nums[i],按规则所能达到的最大值//
		Dp.assign(len, 0);

		Dp[0] = vNodeNums[0];
		Dp[1] = vNodeNums[1];
		int maxDp = Max(Dp[0], Dp[1]);
		for (int i = 2; i < len;i++)
		{
			Dp[i] = vNodeNums[i];
			for (int j = 0; j <= i-2;++j)
			{
				Dp[i] = Max(Dp[i], Dp[j] + vNodeNums[i]);
			}	
			maxDp = Max(maxDp, Dp[i]);
		}

		return maxDp;	
	}

private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};
*/

class Solution {
public:
	int rob(TreeNode* root) {

		Money maxMon = Dfs(root);
		return maxMon.Rob;
	}

private:
	struct Money
	{
		int Rob; //当前节点抢劫获得最大利益
		int notRob;//当前节点不抢获取的最大利益
		Money() :Rob(0), notRob(0){};
	};


	Money Dfs(TreeNode* root)
	{
		Money curMoney;
		if (root==NULL)
		{
			return curMoney;
		}

		Money lMoney = Dfs(root->left);
		Money rMoney = Dfs(root->right);

		Money maxM;
		maxM.notRob = lMoney.Rob + rMoney.Rob;
		maxM.Rob = Max(lMoney.notRob + rMoney.notRob + root->val, maxM.notRob);

	    return maxM;
	
	}
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}

};

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);
	root->left->right->left = new TreeNode(5);

	//TreeNode* root = new TreeNode(4);
	//root->left = new TreeNode(1);
	//root->left->left = new TreeNode(2);
	//root->left->left->left = new TreeNode(3);


	Solution testCase;

	cout << testCase.rob(root) << endl;

	getchar();
	return 0;
}