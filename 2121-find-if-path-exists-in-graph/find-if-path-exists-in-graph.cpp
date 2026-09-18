class Solution {
public:

    bool pathHelper(int src , int destination , 
                    vector<vector<int>> &graph ,
                    vector <bool> & vis) {
        // Base Case
        if(src == destination) {
            return true;
        }

        // Mark the current node visited
        vis[src] = true;

        // Visit all neigbours
        for(int v : graph[src]) {

            if(!vis[v]) {

                if(pathHelper(v , destination , graph ,vis)) {
                    return true;
                }
            }
        }

        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // Create adjacency list
        vector<vector<int>> graph(n);

        // Build Graph
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Visited array
        vector <bool> vis(n,false);

        // DFS
        return pathHelper(source , destination , graph , vis);
    }
};