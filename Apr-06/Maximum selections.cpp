https://practice.geeksforgeeks.org/problems/87ecf96cfd61e511c697c8c94d21c5de7f471fcb/1

int max_non_overlapping( vector< vector<int> >& ranges )
    {
        vector<pair<int, int>> ar;
        for(int i = 0; i < ranges.size(); ++i) {
            ar.push_back({ranges[i][1], ranges[i][0]});
        }
        sort(ar.begin(), ar.end());
        
        int end = ar[0].first; 
        int ans = 1;
        for(int i = 1; i < ar.size(); ++i) {
            if(ar[i].second >= end) {
                ans += 1;
                end = ar[i].first;
            }
        }
        return ans;
    }
