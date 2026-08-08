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

    TreeNode* getInorderSuccessor(TreeNode* root) {
        while(root -> left != NULL) {
            root = root -> left;
        }

        return root;   // Inorder Succesor
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(key < root -> val) {
            root -> left = deleteNode(root -> left , key);
        }
        else if(key > root -> val) {
            root -> right = deleteNode(root -> right , key);
        }

        else {
            // root == val
            //Case1: 0 children
            if(root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            }

            // Case2 : 1 Child
            if(root -> left == NULL || root -> right == NULL) {
                TreeNode* child = (root -> left == NULL) ? root -> right : root -> left;
                delete root;
                return child;
            }

            //Case 3 : 2 child
            TreeNode* IS = getInorderSuccessor(root -> right);
            root -> val = IS -> val;
            root -> right = deleteNode(root -> right , IS -> val); // CASE1 , CASE2
        }

        return root;
    }
};