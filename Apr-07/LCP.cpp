https://practice.geeksforgeeks.org/problems/cf0cd86c66d07222499f84ec22dbcf6cae30e848/1#

Solution *child[26];
   bool isEnd;
   Solution *getnode() {
       Solution* newNode = new Solution;
       newNode->isEnd = false;
       for(int i = 0; i < 26; ++i)
            newNode->child[i] = NULL;
       return newNode;
   }
   void insert(Solution* root, string s) {
       Solution* node = root;
       for(int i = 0; i < s.size(); ++i) {
           int index = s[i] - 'a';
           if(!root->child[index])
              root->child[index] = getnode();
           root = root->child[index];
       }
       root->isEnd = true;
   }
   bool check(Solution* root) {
       int cnt = 0;
       for(int i = 0; i < 26; ++i) {
           if(root->child[i]) cnt += 1;
           if(cnt > 1) return false;
       }
       return true;
   }
   string findPrefix(Solution* root, char ch) {
       string prefix = "";
       while(check(root) && !root->isEnd) {
           for(int i = 0; i < 26; ++i) {
               if(root->child[i]){
                   prefix += char(97 + i);
                   root = root->child[i];
                   break;
               }
           }
       }
       return prefix;
   } 
   string LCP(string ar[], int n)
    {
        Solution *root = getnode();
        for(int i = 0; i < n; ++i) 
           insert(root, ar[i]);
        
        string ans = findPrefix(root, ar[0][0]);
        if(ans.size() == 0) return "-1";
        return ans;
    }
