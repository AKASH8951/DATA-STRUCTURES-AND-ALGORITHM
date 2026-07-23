class Solution {
public:

    static bool compare(vector <int> &a , vector <int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // sort by end time
        sort(intervals.begin(),intervals.end(),compare);

        int count = 0 ;

        int currTime = intervals[0][1];

        for(int i = 1 ; i < intervals.size(); i++) {

            if(intervals[i][0] < currTime) {
                //Overlapping
                count++;
            }
            else {
                currTime = intervals[i][1];
            }
        }

        return count;
    }
};