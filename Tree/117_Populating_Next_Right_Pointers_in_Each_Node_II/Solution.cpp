// 117. Populating Next Right Pointers in Each Node II

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include <queue>
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
       queue<Node*> nodeQueue;

       if(root) nodeQueue.push(root);

       while(nodeQueue.size())
       {
			int length = nodeQueue.size();
			for(int i=0;i<length;i++)
			{
				Node* currentNode = nodeQueue.front();
				nodeQueue.pop();

				if(i!=length-1)
				{
					currentNode->next = nodeQueue.front();
				}

				if(currentNode->left) nodeQueue.push(currentNode->left);
				if(currentNode->right) nodeQueue.push(currentNode->right);
			}
       }

       return root; 
    }
};