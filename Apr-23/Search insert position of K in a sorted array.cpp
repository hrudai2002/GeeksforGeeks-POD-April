int searchInsertK(vector<int> a, int N, int k)
    {
        int l = 0, r = N - 1;
        while(l < r) {
            int m = (l + r) >> 1;
            if(a[m] == k)
               return m;
            else if(a[m] < k)
                l = m + 1;
            else 
                r = m - 1;
        }
        if(a[l] == k)
           return l;
        if(a[l] > k) return l;
        return (l + 1);
    }
