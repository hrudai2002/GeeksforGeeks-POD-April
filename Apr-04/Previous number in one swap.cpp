https://practice.geeksforgeeks.org/problems/previous-number-in-one-swap5707/1


string previousNumber(string s){
        int n = s.size();
        int idx = n;
        for(int i = s.size() - 2; i >= 0; --i) {
            if(s[i+1] < s[i]) {
                idx = i;
                break;
            }
        }
        if(idx == n) {
            return "-1";
        }
        char mx = 47;
        int mxidx = n;
        for(int i = idx + 1; i < s.size(); ++i) {
            if(s[i] < s[idx]) {
                if(s[i] > mx) {
                    mx = s[i];
                    mxidx = i;
                }
                
            }
        }
        swap(s[idx], s[mxidx]);
        if(s[0] == '0') return "-1";
        return s;
    }
