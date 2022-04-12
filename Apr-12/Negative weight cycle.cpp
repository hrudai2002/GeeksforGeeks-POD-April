https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

bool Bfs(int node, int n, vector<pair<int, int>> adj[]) {
        queue<pair<int, int>> q;
        vector<bool> vis(n + 1, false);
        q.push({node, 0});
        while(!q.empty()) {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();
            vis[u] = true;
            for(auto v : adj[u]) {
                if(vis[v.first]) {
                    if(w + v.second < 0) return true;
                }
                else{
                  q.push({v.first, w + v.second});
                }
            }
        }
        return false;
    }
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<pair<int, int>> adj[n + 1];
	    for(int i = 0; i < edges.size(); ++i) {
	        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
	    }
	    for(int i = 0; i < n; ++i) {
	        if(Bfs(i, n, adj)) return 1;
	    }
	    return 0;
	}
