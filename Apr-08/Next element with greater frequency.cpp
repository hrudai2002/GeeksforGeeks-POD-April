https://practice.geeksforgeeks.org/problems/9656e96f6eaee49e67400fa2aed7833c8d9846b8/1#

vector<int> print_next_greater_freq(int arr[],int n)
    {
        vector<int> ans;
        unordered_map<int, int> mp, high; 
        for(int i = 0; i < n; ++i) 
           mp[arr[i]]++; 
        
        stack<pair<int, int>> s;
        for(int i = 0; i < n; ++i) {
            if(s.empty()) {
                s.push({arr[i], i});
            }
            else {
                while(!s.empty() && mp[s.top().first] < mp[arr[i]]) {
                    high[s.top().second] = arr[i];
                    s.pop();
                }
                s.push({arr[i], i});
            }
        }
        while(!s.empty()) {
           high[s.top().second] = -1;
           s.pop();
        }
        for(int i = 0; i < n; ++i)
           ans.push_back(high[i]);
        return ans;
    }
