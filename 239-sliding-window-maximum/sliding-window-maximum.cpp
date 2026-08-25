class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        priority_queue<pair<int,int>> pq;
        vector <int> ans;

        for(int i = 0 ; i < k ; i++) {
            pq.emplace(arr[i] , i);
        }
        ans.push_back(pq.top().first);

        for(int i = k ; i < arr.size() ; i++) {
            while(!pq.empty() && pq.top().second <= i-k) {
                pq.pop();
            }

            pq.emplace(arr[i],i);
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};