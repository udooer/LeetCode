// 102. Binary Tree Level Order Traversal

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {   
    	queue<TreeNode*> nodeQueue;
    	vector<vector<int>> ans;
    	if(root == nullptr) return ans;
    	nodeQueue.push(root);

    	while(nodeQueue.empty() == false)
    	{
    		int size = nodeQueue.size();
    		vector<int> vec;
    		for(int i=0;i<size;i++)
    		{
    			TreeNode* tmp = nodeQueue.front();
    			nodeQueue.pop();
    			vec.push_back(tmp->val);
    			if(tmp->left) nodeQueue.push(tmp->left);
    			if(tmp->right) nodeQueue.push(tmp->right);
    		}
    		ans.push_back(vec);
    	}

    	return ans;
    }
};