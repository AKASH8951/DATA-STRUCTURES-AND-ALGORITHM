class Solution {
public:
    void reverseString(vector<char>& str) {
        stack <int> s;
        for(int i= 0 ; i<str.size() ; i++) {
            s.push(str[i]);
        }

        int i = 0;
        while(!s.empty()) {
            str[i] = s.top();
            s.pop();
            i++;
        }
    }
    
};