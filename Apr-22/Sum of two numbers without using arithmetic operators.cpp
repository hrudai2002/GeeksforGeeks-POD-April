https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-without-using-arithmetic-operators/1

int sum(int a , int b)
    {
        int num1[32] = {0}, num2[32] = {0}, res[32] = {0};
        for(int i = 31; i >= 0; --i) {
            if(a & (1 << i))
                num1[i] = 1;
        }
        for(int i = 31; i >= 0; --i) {
            if(b & (1 << i))
               num2[i] = 1;
        }
        int c = 0;
        for(int i = 0; i < 32; ++i) {
            if(num1[i] == 0 && num2[i] == 0) {
               res[i] = 0 + c;
               c = 0; 
            }
            else if(num1[i] == 1 && num2[i] == 1) {
                res[i] = (2 + c) % 2;
                c = (2 + c) / 2;
            }
            else {
                res[i] = (1 + c) % 2;
                c = (1 + c) / 2;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            if(res[i]) ans += (1 << i);
        }
        return ans;
    }
