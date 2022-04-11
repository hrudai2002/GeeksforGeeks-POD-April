https://practice.geeksforgeeks.org/problems/b5e2a639b39537ea71e4551a4274383bda1c9a34/1#

int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{   
	    if(mat[r][c] == '#') return 0;
		queue<pair<pair<int,int>, pair<int, int>>> q;
		q.push({{r, c},{0, 0}});
		mat[r][c] = '1';
		while(!q.empty()) {
		    int x = q.front().first.first;
		    int y = q.front().first.second;
		    int up = q.front().second.first;
		    int down = q.front().second.second;
		    q.pop();
		    
		    if(y - 1 >= 0 && mat[x][y - 1] == '.'){
		        q.push({{x, y - 1}, {up, down}});
		        mat[x][y - 1] = '1';
		    }
		    if(y + 1 < m && mat[x][y + 1] == '.') {
		        q.push({{x, y + 1}, {up, down}});
		        mat[x][y + 1] = '1';
		    }
		    
		    if(x - 1 >= 0 && mat[x - 1][y] == '.' && up + 1 <= u) {
		        q.push({{x - 1, y}, {up + 1, down}});
		        mat[x - 1][y] = '1';
		    }
		    
		    if(x + 1 < n && mat[x + 1][y] == '.' && down + 1 <= d) {
		        q.push({{x + 1, y}, {up, down + 1}});
		        mat[x + 1][y] = '1';
		    }
		    
		}
		int ans = 0;
		for(int i = 0; i < n; ++i) {
		    for(int j = 0; j < m; ++j) {
		        if(mat[i][j] == '1') ans += 1;
		    }
		}
		return ans;
	}
