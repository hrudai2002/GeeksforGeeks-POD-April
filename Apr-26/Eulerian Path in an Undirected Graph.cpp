https://practice.geeksforgeeks.org/problems/eulerian-path-in-an-undirected-graph5052/1#

int eulerPath(int N, vector<vector<int>> graph){
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            int e = 0;
            for(int j = 0; j < N; ++j) {
                if(graph[i][j]) 
                   e++;
            }
            if(e & 1) cnt++;
        }
        return cnt == 2;
    }
