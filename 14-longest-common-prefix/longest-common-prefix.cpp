class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());
        string ans ="";
        string first = strs.front();
        string last = strs.back();

        int i = 0;
        while(i < first.size() && i < last.size()
            && first[i] == last[i]) {
                i++;
            }
        for(int j = 0 ; j < i ; j++) {
            ans += first[j];
        }

        return ans;
    }
};