// 105. Construct Binary Tree from Preorder and Inorder Traversal


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) 
        {
            m_valToIndexMap[inorder[i]] = i;
        }

        return ConstructRoot(preorder, 0, inorder.size() - 1);
    }

    TreeNode* ConstructRoot(vector<int>& preorder, int inorderLeft, int inorderRight) 
    {
        if (inorderLeft > inorderRight) 
        {
            return nullptr;
        }

        int val = preorder[m_preorderIndex];
        TreeNode* treeNode = new TreeNode(val);
        m_preorderIndex++;
        treeNode->left = ConstructRoot(preorder, inorderLeft, m_valToIndexMap[val] - 1);
        treeNode->right = ConstructRoot(preorder, m_valToIndexMap[val] + 1, inorderRight);

        return treeNode;
    }
private:
    unordered_map<int, int> m_valToIndexMap;
    int m_preorderIndex;
};