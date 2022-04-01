https://practice.geeksforgeeks.org/problems/maximum-product-of-increasing-subsequence-of-size-32027/1#

vector<int> maxProductSubsequence(int *arr , int n) 
    {  
       set<int> s;
       s.insert(arr[0]);
       vector<int> rightMax(n + 1, 0);
       rightMax[n - 1] = arr[n - 1];
       for(int i = n - 2; i >= 0; --i)
         rightMax[i] = max(arr[i], rightMax[i + 1]);
       
       vector<int> ans;
       long long int mxpro = 0;
       for(int i = 1; i < n - 1; ++i) {
           int right = rightMax[i + 1];
           auto it = s.lower_bound(arr[i]);
           if(it == s.begin()) {
               s.insert(arr[i]);
               continue;
           }
           it--;
           int left = *it;
           s.insert(arr[i]);
           long long int p = left * 1LL * arr[i] * 1LL * right;
           if(((left < arr[i]) && (arr[i] < right)) && (mxpro <= p)) {
               mxpro = p;
               ans = {left, arr[i], right};
           }
          
       }
       if(ans.empty()) {
           return {-1};
       }
       return ans;
    } 
