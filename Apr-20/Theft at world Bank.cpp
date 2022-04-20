bool perfectSquare(long long w) {
	    long long l = 0, r = w;
	    while(l <= r) {
	        long long m = (l + r) >> 1;
	        if(m*m == w) 
	          return true;
	        else if(m*m < w)
	          l = m + 1;
	        else 
	          r = m - 1;
	    }
	    return false;
	}
	long double maximumProfit(int N, long long C, vector<long long> W, vector<long long> P){
	    vector<pair<long double, long long>> ar;
	    for(int i = 0; i < N; ++i) {
	        ar.push_back({P[i]/(long double)W[i], i});
	    }
	    sort(ar.rbegin(), ar.rend());
	    
	    long double tw = 0, tp = 0;
	    for(int i = 0; i < N; ++i) {
	        long long p = P[ar[i].second];
	        long long w = W[ar[i].second];
	        
	        if(!perfectSquare(w)) {
	            if(tw + w <= C) {
	                tw += w;
	                tp += p;
	            }
	            else {
	                tp += (((C - tw)*p)/(long double)w);
	                return (tp * 1000.0) / 1000.0;
	            }
	        }
	    }
	    
	    return (tp * 1000.0) / 1000.0;
	}
