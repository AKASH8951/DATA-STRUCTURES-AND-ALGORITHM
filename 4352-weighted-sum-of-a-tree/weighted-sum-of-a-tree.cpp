class Solution {
public:    
        int height;
        vector< vector< int >> children;
        void dfsHeight(int node , int depth) {
            height = max(height , depth);
        for(int child : children[node]) {
            dfsHeight(child , depth + 1);
        }
    }    
        long long dfsSum(int node, int depth , vector <int> &nums) {
            long long ans = 0;
            ans += 1LL * nums[node] * (height - depth + 1);

            for(int child: children[node]) {
                ans += dfsSum(child , depth + 1 , nums);
            }
        return ans;                
        }
        long long weightedSum(vector <int>& parent , vector <int> & nums) {
            int n = parent.size();
            children.resize(n);
            for(int i = 1 ; i < n ; i++) {
                children[parent[i]].push_back(i);
            }
            // Find height
            height = 0;
            dfsHeight(0,1);
            return dfsSum(0,1,nums);
        }    
};