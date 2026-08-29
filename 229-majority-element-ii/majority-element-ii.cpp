class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> map;
        vector<int> ans;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(map.count(nums[i])) {
                map[nums[i]]++;
            }
            else {
                map[nums[i]] = 1;
            }
        }
        for(pair <int , int>p : map) {
            if(p.second > nums.size()/3) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};