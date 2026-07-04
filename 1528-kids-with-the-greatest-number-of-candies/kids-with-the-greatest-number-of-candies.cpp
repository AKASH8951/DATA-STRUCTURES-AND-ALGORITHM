class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int extraCandies) {
        int n = arr.size();
        vector<bool>ans;

        int max_val = INT_MIN;
        
        for(int val: arr){
            max_val = max(max_val,val);
        }

        for(int val:arr){
            if(val + extraCandies >= max_val){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};