class Solution {
public:
    vector<int> separateDigits(vector<int>& arr) {
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= 9) {
                ans.push_back(arr[i]);
            } else {
                int num = arr[i];
                int pos = ans.size();

                while (num > 0) {
                    ans.insert(ans.begin() + pos, num % 10);
                    num /= 10;
                }
            }
        }

        return ans;
    }
};