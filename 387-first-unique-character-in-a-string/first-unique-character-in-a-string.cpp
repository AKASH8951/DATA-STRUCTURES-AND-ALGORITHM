class Solution {
public:
    int firstUniqChar(string str) {
        queue <int> Q;
        int freq[26] = {0};

        for(int i = 0 ; i < str.size() ; i++) {
            char ch = str[i];
            Q.push(i);
            freq[ch - 'a']++;
        }

        while(!Q.empty() && freq[str[Q.front()] - 'a'] > 1) {
            Q.pop();
        }
        if(Q.empty()) {
            return -1;
        }

        return Q.front();
    }
};