class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);   // fix: allocate size
        stack<int> s;

        // First pass to handle circular nature
        for (int idx = n - 1; idx >= 0; idx--) {
            int curr = arr[idx];

            while (!s.empty() && curr >= s.top()) {
                s.pop();
            }

            s.push(curr);
        }

        // Your original right-to-left logic
        for (int idx = n - 1; idx >= 0; idx--) {
            int curr = arr[idx];

            while (!s.empty() && curr >= s.top()) {
                s.pop();
            }

            if (s.empty()) {
                ans[idx] = -1;
            }
            else {
                ans[idx] = s.top();
            }

            s.push(curr);
        }

        return ans;
    }
};