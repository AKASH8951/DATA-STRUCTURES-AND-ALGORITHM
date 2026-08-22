class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        // first subarray
        double sum = 0;
        for(int i = 0 ; i < k ; i++) {
            sum += arr[i];
        }
        double mx = sum / k;
        for(int i = k ; i < arr.size() ; i++) {
            sum += arr[i] - arr[i-k];
            mx = max(sum/k,mx);
        }

        return mx;
    }
};