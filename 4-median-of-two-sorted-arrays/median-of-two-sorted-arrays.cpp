class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector <int> merged;
        int left = 0 , right = 0;

        while(left < n && right < m) {
            if(nums1[left] < nums2[right]) {
                merged.push_back(nums1[left]);
                left++;
            }
            else {
                merged.push_back(nums2[right]);
                right++;
            }
        }
        while(left < n) {
            merged.push_back(nums1[left]);
            left++;
        }
        while(right < m) {
            merged.push_back(nums2[right]);
            right++;
        }
        
        int size = merged.size();
        int mid = size / 2;

        if (size % 2 == 1) {
        return merged[mid];
}

        return (merged[mid - 1] + merged[mid]) / 2.0; 
       
        
    }
};