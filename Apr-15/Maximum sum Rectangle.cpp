https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

int kadane(vector<int> ar) {
        int sum = ar[0], bestsum = ar[0];
        for(int i = 1; i < ar.size(); ++i) {
            sum = max(ar[i], sum + ar[i]);
            bestsum = max(sum, bestsum);
        }
        return bestsum;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> M) {
        int maxRect = INT_MIN;
        for(int i = 0; i < r; ++i) {
            vector<int> prefixSum(c, 0);
            for(int j = i; j < r; ++j) {
                for(int k = 0; k < c; ++k) {
                    prefixSum[k] += M[j][k];
                }
                maxRect = max(maxRect, kadane(prefixSum));
            }
        }
        return maxRect;
    }
