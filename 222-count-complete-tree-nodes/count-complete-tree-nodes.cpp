class Solution {
public:
    int getHeight(TreeNode* root) {
        int h = 0;

        while (root) {
            h++;
            root = root->left;
        }

        return h;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) {
            // Left subtree is perfect
            return (1 << leftHeight) + countNodes(root->right);
        }
        else {
            // Right subtree is perfect
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};