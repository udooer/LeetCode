// 199. Binary Tree Right Side View
/*

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    unordered_map<int, int> IndexToValueMap;

    void BuildMap(TreeNode* node, int index) 
    {
        IndexToValueMap[index] = node->val;

        if (node->left) 
        {
            BuildMap(node->left, index * 2);
        }

        if (node->right) 
        {
            BuildMap(node->right, index * 2 + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root) BuildMap(root, 1);
        else return ans;

        int level = 1;
        
        while (true) 
        {
            int indexRear = pow(2, level) - 1;
            int indexFront = indexRear - pow(2, level - 1);
            
            bool isContain = false;
            for (int i = indexRear; i > indexFront; i--) 
            {
                if (IndexToValueMap.count(i)) 
                {
                    ans.push_back(IndexToValueMap[i]);
                    isContain = true;
                    break;
                }
            }

            if (isContain == false) 
            {
                break;
            }

            level++;
        }

        return ans;
    }
};

#include <queue>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        queue<TreeNode*> nodeQueue;
        if(root) nodeQueue.push(root);

        vector<int> ans;
        while (nodeQueue.size()) 
        {
            int length = nodeQueue.size();
            for (int i = 0; i < length - 1; i++)
            {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);
            }

            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left) nodeQueue.push(node->left);
            if (node->right) nodeQueue.push(node->right);
            ans.push_back(node->val);
        }

        return ans;
    }
};