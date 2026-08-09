class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // 2D Prefix Sum
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        // Check whether two non-overlapping k x k squares exist
        auto possible = [&](int k) -> bool {

            int minRow = m;
            int maxRow = -1;

            int minCol = n;
            int maxCol = -1;

            for (int r = 0; r + k <= m; r++) {
                for (int c = 0; c + k <= n; c++) {

                    // Number of 1s in this k x k square
                    int ones =
                        pref[r + k][c + k]
                        - pref[r][c + k]
                        - pref[r + k][c]
                        + pref[r][c];

                    // Not a completely usable square
                    if (ones != k * k)
                        continue;

                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);

                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);

                    // Two squares can be separated vertically
                    if (maxRow - minRow >= k)
                        return true;

                    // Two squares can be separated horizontally
                    if (maxCol - minCol >= k)
                        return true;
                }
            }

            return false;
        };

        // Binary search on k
        int low = 1;
        int high = min(m, n);
        int best = 0;

        while (low <= high) {

            int k = low + (high - low) / 2;

            if (possible(k)) {
                best = k;
                low = k + 1;
            }
            else {
                high = k - 1;
            }
        }

        return best * best;
    }
};