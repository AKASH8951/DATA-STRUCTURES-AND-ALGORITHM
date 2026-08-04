class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
        vector <int> ans;

        int mini = *min_element(arr.begin() , arr.end());
        int maxi = *max_element(arr.begin() , arr.end());

        unordered_set <int> st(arr.begin() , arr.end());

        for(int i = mini ; i <= maxi ; i++) {
            if(!st.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};