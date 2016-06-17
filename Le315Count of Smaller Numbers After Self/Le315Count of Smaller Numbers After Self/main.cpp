#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) 
	{
		vector<int> result;
		int len = nums.size();

		result.assign(len, 0);
		int count;
		for (int i = 0; i < len;i++)
		{
			count = 0;
			for (int j = i + 1; j < len;j++)
			{
				if (nums[j]<nums[i])
				{
					count++;
				}
			}
			result[i] = count;
		}

		return result;
	}
};


class Solution2 {

	struct TreeNode{
		int val;
		int cnt;//left Node num
		int same; //same node num
		TreeNode *left, *right;
		TreeNode(int v) :val(v), cnt(0), same(1),right(NULL),left(NULL){};
	};
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> result;
		int len = nums.size();
		result.assign(len, 0);
		
		TreeNode* root = NULL;
		for (int i = len - 1; i >= 0;i--)
		{
			result[i] = Insert(root, nums[i]);
		}

		return result;

	};

private:
	int Insert(TreeNode* &root, int val)
	{
		if (root==NULL)
		{
			root = new TreeNode(val);
			return 0;
		}

		TreeNode* tNode = root;
		int count = 0;
		while (tNode!=NULL)
		{
			if (tNode->val>val)
			{
				tNode->cnt++;
				if (tNode->left==NULL)
				{
					tNode->left = new TreeNode(val);
					break;
				}
				tNode = tNode->left;
			}else if (tNode->val<val)
			{
				count += tNode->cnt + tNode->same;
				if (tNode->right==NULL)
				{
					tNode->right = new TreeNode(val);
					break;
				}
				tNode = tNode->right;
			}
			else
			{
				count += tNode->cnt;
				tNode->same++;
				break;
			}
		}
		return count;
	}
};



int main()
{

	vector<int> nums = { 5, 2, 6, 1 };
	Solution2 testCase;

	vector<int> result = testCase.countSmaller(nums);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i]<<" ";
	}

	getchar();
	return 0;
}