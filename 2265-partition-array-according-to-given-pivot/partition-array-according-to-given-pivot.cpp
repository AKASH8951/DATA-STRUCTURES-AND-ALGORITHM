class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> ans;

        // If Element is smaller than in Pivot
        for(int x : nums) {
            if(x < pivot)
                ans.push_back(x);
        }
        // Push Pivot element in ans array
        for(int x : nums) {
            if(x == pivot) 
                ans.push_back(x);
        }
        // Push Greater Elements than pivot
        for(int x : nums) {
            if(x > pivot)
                ans.push_back(x);
        }

        return ans;
    }
};