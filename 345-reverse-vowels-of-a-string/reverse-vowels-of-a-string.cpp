class Solution {
public:
    string reverseVowels(string s) {

        vector<char> helper;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' ||
               s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {

                helper.push_back(s[i]);
                s[i] = '#';
            }
        }
        if (helper.empty())
        return s;

        int si = helper.size() - 1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '#') {
                s[i] = helper[si];
                si--;
            }
        }

        return s;
    }
};