https://practice.geeksforgeeks.org/problems/k-ary-tree1235/1

long long m = 1000000007;
    long long power(long long a, long long b) { a %= m; long long res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
    long long karyTree(int k, int m) {
        return power(k, m);
    }
