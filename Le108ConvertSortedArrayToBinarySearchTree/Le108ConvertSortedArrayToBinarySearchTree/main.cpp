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
	TreeNode* sortedArrayToBST(vector<int>& nums) {


		return GenBST(0, nums.size() - 1, nums);
	}

private:
	TreeNode* GenBST(int left, int right, vector<int>& nums)
	{
			if (left>right)
			{
				return NULL;
			}else if (left==right)
			{
				return new TreeNode(nums[left]);
			}
			else
			{
				int mid = (left + right) / 2;
				TreeNode* TNode = new TreeNode(nums[mid]);
				TNode->left = GenBST(left, mid - 1, nums);
				TNode->right = GenBST(mid + 1, right, nums);
				return TNode;
			}			
	}

};


int main()
{

	getchar(); 
	return 0;
}

