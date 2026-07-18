class Solution {
public:
    int findGCD(vector<int>& nums) {
        int size = nums.size();
        int smallest = INT_MAX;
        int largest= INT_MIN;
        int ans;

        for(int val:nums){
            smallest = min(smallest , val);
            largest = max(largest, val);
        } 

        ans = gcd(smallest , largest);
        return ans;
    }
};