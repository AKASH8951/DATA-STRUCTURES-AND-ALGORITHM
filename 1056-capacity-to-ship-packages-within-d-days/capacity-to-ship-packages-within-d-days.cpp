class Solution {
public:
    int shipWithinDays(vector<int>& weight, int days) {
        int start = 0; 
        int end = 0;
        int ans;

        for(int weights : weight) {
            start = max(start , weights);
            end += weights;
        }

        while(start <= end) {
            int capacity = start + (end - start) / 2;
            int load = 0 , day = 1;
            for(int i = 0 ; i < weight.size() ; i++)  {
                load += weight[i];
                if(load > capacity) {                
                    day++;
                    load = weight[i];
                }
            }
                if(day <= days) {
                    ans = capacity;
                    end = capacity -1 ;
                }
                else {
                    start = capacity + 1;
                }

            
        }
        return ans;
    }
};