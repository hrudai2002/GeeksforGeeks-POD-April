vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    int n = str.size();
	    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
	    for(int i = 0; i < n; ++i)
	      dp[i + 1][str[i] - 'a'] = 1;
	    for(int i = 0; i < 26; ++i) {
	        for(int j = 1; j <= n; ++j)
	           dp[j][i] += dp[j - 1][i];
	    }
	    vector<int> ans;
	    for(int i  = 0; i < Query.size(); ++i){
	        int l = Query[i][0];
	        int r = Query[i][1];
	        
	        int res = 0;
	        for(int i = 0; i < 26; ++i)
	           if(dp[r][i] - dp[l - 1][i] > 0) res++;
	        ans.push_back(res);
	    }
	    return ans;
	}
