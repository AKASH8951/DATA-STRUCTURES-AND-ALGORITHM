class Solution {
public:
    bool rootToNodePath(TreeNode* root, TreeNode* node,
                        vector<TreeNode*>& path) {

        if(root == NULL)
            return false;

        path.push_back(root);

        if(root == node)
            return true;

        if(rootToNodePath(root->left, node, path) ||
           rootToNodePath(root->right, node, path))
            return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        vector<TreeNode*> path1, path2;

        rootToNodePath(root, p, path1);
        rootToNodePath(root, q, path2);

        TreeNode* lca = nullptr;

        int i = 0;
        while(i < path1.size() && i < path2.size()) {
            if(path1[i] != path2[i])
                break;

            lca = path1[i];
            i++;
        }

        return lca;
    }
};