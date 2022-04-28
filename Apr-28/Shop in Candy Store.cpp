vector<int> candyStore(int a[], int n, int k)
    {
        sort(a, a + n);
        int i = 0, j = n - 1;
        int mn = 0, mx = 0;
        while(i <= j) {
            mn += a[i];
            j -= k;
            i += 1;
        }
        i = 0, j = n - 1;
        while(i <= j) {
            mx += a[j];
            i += k;
            j--;
        }
        return {mn, mx};
    }
