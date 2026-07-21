class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int size = height.size();
        vector <int> nsl(size); // Next Smaller left
        vector <int> nsr(size); // Next smaller Right
        stack <int> s;

        // Next smaller left
        nsl[0] = -1;
        s.push(0);
        for(int i = 1 ; i < height.size() ; i++) {
            int curr = height[i];
            while(!s.empty() && curr <= height[s.top()]) {
                s.pop();
            }

            if(s.empty()) {
                nsl[i] = -1;
            }
            else {
                nsl[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }

        // Next smaller Right
        int n = height.size();
        nsr[n-1] = n;
        s.push(n-1);

        for(int i = n-2 ; i >= 0 ; i--) {
            int curr = height[i];
            while(!s.empty() && curr <= height[s.top()]) {
                s.pop();
            }
            if(s.empty()) {
                nsr[i] = n;
            }
            else {
                nsr[i] = s.top();
            }

            s.push(i);
        } 

        int maxArea = 0;
        for(int i = 0 ; i < height.size() ; i++) {
            int ht = height[i];
            int width = nsr[i] - nsl[i] - 1;
            int area = ht * width;
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};