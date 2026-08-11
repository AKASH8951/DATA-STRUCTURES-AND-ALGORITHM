class Solution {
public:
    void PathHelper(TreeNode* root, string path , vector <string> &ans) {
        if (root == NULL) {
            return;
        }

        path += to_string(root -> val);
        

        // Leaf Node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";

        PathHelper(root->left, path , ans);
        PathHelper(root->right, path , ans);

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        PathHelper(root,"",ans);
        return ans;
    }
};