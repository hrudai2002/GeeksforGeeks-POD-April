class Solution:
    def s(self, n):
        return ((n*(n + 1)*(2*n + 1)) // 6)
    def killinSpree (self, n):
        if n == 1:
            return 1
        l, r = 0, n
        while l + 1 < r:
           m = (l + r) >> 1
           if self.s(m) == n:
               return m
           elif self.s(m) < n:
               l = m
           else:
               r = m - 1;
        
        if self.s(r) < n:
            return r
        return l 

