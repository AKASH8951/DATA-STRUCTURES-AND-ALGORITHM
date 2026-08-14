class Info {
public:
    bool isBST;
    int min;
    int max;
    int sum;
    Info(bool isBST , int min , int max , int sum) {
        this -> isBST = isBST;
        this -> max = max;
        this -> min = min;
        this -> sum = sum;
    }
};
class Solution {
public:

    int maxSum = 0;
    Info* solve(TreeNode* root) {
        if(root == NULL) {
            return new  Info(true , INT_MAX , INT_MIN , 0);
        }
        Info* leftInfo = solve(root -> left);
        Info* rightInfo = solve(root -> right);

        int currsum = leftInfo -> sum + rightInfo -> sum + root -> val;

        int currMin = min(root -> val , 
        min(leftInfo -> min , rightInfo -> min));
        
        int currMax = max(root -> val ,
         max(leftInfo -> max , rightInfo -> max));

        if(leftInfo -> isBST && 
        rightInfo -> isBST &&
        root -> val > leftInfo -> max &&
        root -> val < rightInfo -> min) {
            maxSum = max(maxSum , currsum);

            return new Info(true , currMin , currMax , currsum);
        }
        return new Info(false , currMin , currMax , currsum);

    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};