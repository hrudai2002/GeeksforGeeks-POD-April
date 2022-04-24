long long m = (long long)1e9 + 7;
    bool prime(long long n){
        for(long long i = 2; i <= sqrt(n); ++i) {
            if(n % i == 0) return false;
        }
        return true;
    }
    long long primeProduct(long long l, long long r){
        long long ans = 1;
        for(long long i  = l; i <= r; ++i){
            if(prime(i)) {
                ans = (ans%m * i%m)%m;
            }
        }
        return ans;
    }
