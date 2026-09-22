class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // -1 ~ not colored
        // 0 ~ color 0
        // 1 ~ color 1
        vector <int> color(n,-1);

        for(int i = 0 ; i < n ; i++) {

            // Graph can have disconnected components
            if(color[i] != -1) {
                continue;
            }

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v : graph[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else {
                        if(color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};