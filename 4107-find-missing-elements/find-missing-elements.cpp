class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
        vector <int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int x: arr) {  // FIND MAX FROM ARRAY
            maxi = max(maxi , x);
        }

        for(int x: arr) {  // FIND MIN FROM ARRAY
            mini = min(mini , x);
        }

        for(int i = mini ; i <= maxi ; i++) {
            bool found = false;

            for(int x: arr) {
                if(x == i) {
                    found = true;
                    break;
                }
            }

            if(!found) 
                ans.push_back(i);

        }




        return ans;


    }
};