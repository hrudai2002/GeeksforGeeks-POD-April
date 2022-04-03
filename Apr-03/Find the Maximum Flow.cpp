https://practice.geeksforgeeks.org/problems/find-the-maximum-flow2126/1

bool bfs(vector<vector<int>>& graph, int n, int s, int t, vector<int> &parent) {
        vector<int> vis(n, 0);
        vis[s] = 1;
        parent[s] = -1;
        queue<int> q;
        q.push(s); 
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v = 0; v < n; ++v) {
                if(!vis[v] && graph[u][v]) {
                    parent[v] = u;
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return (vis[t] == true);
    }
    int fordFulkerson(vector<vector<int>>& graph, int n, int s, int t) {
        vector<int> parent(n, 0);
        int maxflow = 0;
        while(bfs(graph, n, s, t, parent)) {
            int pathflow = INT_MAX;
            for(int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                pathflow = min(pathflow, graph[u][v]);
            }
            for(int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                graph[u][v] -= pathflow;
                graph[v][u] += pathflow;
            }
          
            maxflow += pathflow;
        }
        return maxflow;
    }
    int solve(int n,int m,vector<vector<int>> Edges)
    {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            int u = Edges[i][0];
            int v = Edges[i][1];
            int w = Edges[i][2];
            u--, v--;
            graph[u][v] += w;
            graph[v][u] += w;
            
            if(u == v) 
              graph[u][v] = 0;
        }
        return fordFulkerson(graph, n, 0, n - 1);
    }
