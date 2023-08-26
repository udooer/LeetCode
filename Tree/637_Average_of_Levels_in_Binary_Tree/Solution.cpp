// 637. Average of Levels in Binary Tree


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

#include<vector>
#include<queue>
using namespace std;

class Solution 
{
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
    	queue<TreeNode*> nodeQueue;
    	nodeQueue.push(root);
    	vector<double> ans;
    	while(nodeQueue.empty() == false)
    	{
    		int size = nodeQueue.size();
    		int64_t sum = 0;
    		for(int i=0;i<size;i++)
    		{
    			TreeNode* tmp = nodeQueue.front();
    			nodeQueue.pop();
    			sum += tmp->val;
    			if(tmp->left) nodeQueue.push(tmp->left);
    			if(tmp->right) nodeQueue.push(tmp->right);
    		}
    		ans.push_back((double)sum/size);
    	}

    	return ans;
    }
};