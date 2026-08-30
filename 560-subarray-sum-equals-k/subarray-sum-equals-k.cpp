class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> m; // Prefix -> frequency

        int sum = 0;
        int ans = 0;

        m[0] = 1;

        for(int j = 0 ; j < nums.size() ; j++) {
            sum += nums[j];

            if(m.count(sum-k)) {
                ans += m[sum-k];
            }

            m[sum]++;
        }

        return ans;
    }
};