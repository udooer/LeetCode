// 103. Binary Tree Zigzag Level Order Traversal


//Definition for a binary tree node.
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
#include <deque>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
    	deque<TreeNode*> nodeDeque;
    	vector<vector<int>> ans;
    	if(root == nullptr) return ans;
    	nodeDeque.push_back(root);
    	
    	bool clockwise = true;
    	while(nodeDeque.empty() == false)
    	{
    		int size = nodeDeque.size();
    		vector<int> vec;
    		if(clockwise)
    		{
	    		for(int i=0;i<size;i++)
	    		{
	    			TreeNode* node = nodeDeque.front();
	    			nodeDeque.pop_front();
	    			if(node->left) nodeDeque.push_back(node->left);
	    			if(node->right) nodeDeque.push_back(node->right);
	    			vec.push_back(node->val);
    			}
    		}
    		else
    		{
    			for(int i=0;i<size;i++)
	    		{
	    			TreeNode* node = nodeDeque.back();
	    			nodeDeque.pop_back();
	    			if(node->right) nodeDeque.push_front(node->right);
	    			if(node->left) nodeDeque.push_front(node->left);
	    			vec.push_back(node->val);
    			}
    		}

    		ans.push_back(vec);
    		clockwise = !clockwise;
    	}

    	return ans;
    }
};