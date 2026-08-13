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
class Solution {
public:
    TreeNode* BSTFromSorted(vector <int> &nodes , int st , int end) {
        if(st > end) {
            return NULL;
        }

        int mid = st + (end - st) / 2;
        TreeNode* curr = new TreeNode(nodes[mid]);

        curr -> left = BSTFromSorted(nodes , st , mid - 1);
        curr -> right = BSTFromSorted(nodes , mid + 1 , end);

        return curr;
    }

    void getInorder(TreeNode* root, vector <int> &nodes) {
        if(root == nullptr) {
            return;
        }

        getInorder(root -> left, nodes);
        nodes.push_back(root -> val);
        getInorder(root -> right, nodes);

    }

    TreeNode* balanceBST(TreeNode* root) {
        vector <int> nodes;
        getInorder(root , nodes);

        return BSTFromSorted(nodes , 0 , nodes.size()-1);
    }
};