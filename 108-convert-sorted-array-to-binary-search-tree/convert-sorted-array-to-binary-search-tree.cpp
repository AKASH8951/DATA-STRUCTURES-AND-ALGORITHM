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
    TreeNode* BSThelper(vector <int>& nums , int start , int end) {
        if(start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr -> left = BSThelper(nums , start , mid - 1);
        curr -> right = BSThelper(nums , mid + 1 , end);

        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;
        return BSThelper(nums, start ,end);
    }
};