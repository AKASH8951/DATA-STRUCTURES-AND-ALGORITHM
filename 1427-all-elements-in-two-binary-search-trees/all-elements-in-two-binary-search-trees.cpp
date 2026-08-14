class Solution {
public:

    void getinorder(TreeNode* root , vector <int> &nodes) {
        if(root == NULL) {
            return;
        }
        getinorder(root -> left , nodes);
        nodes.push_back(root -> val);
        getinorder(root -> right , nodes);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> nodes1;
        vector <int> nodes2;
        vector <int> merged;
        
        getinorder(root1 , nodes1);
        getinorder(root2 , nodes2);

        int i = 0;
        int j = 0;

        while(i < nodes1.size() && j < nodes2.size()) {
            if(nodes1[i] < nodes2[j]) {
                merged.push_back(nodes1[i++]);
            }
            else {
                merged.push_back(nodes2[j++]);
            }
        }
        while(i < nodes1.size()) {
            merged.push_back(nodes1[i++]);
        }
        while(j < nodes2.size()) {
            merged.push_back(nodes2[j++]);
        }

        return merged;
    }
};