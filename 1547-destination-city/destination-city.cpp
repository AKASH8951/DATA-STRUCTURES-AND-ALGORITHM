class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> from;

        // Store all staring cities
        for(auto path : paths) {
            from.insert(path[0]);
        }

        // Find destination that never appears as a starting city
        for(auto path : paths) {
            if(from.find(path[1]) == from.end()) {
                return path[1];
            }
        }
        return "";
    }
};