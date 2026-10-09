class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while(left < right) {
            int ht = min(height[left] , height[right]);
            int wid = right - left;

            int area = ht * wid;
            maxWater = max(area , maxWater);

            if(height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
            return maxWater;
    }
};