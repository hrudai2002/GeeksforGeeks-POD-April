https://practice.geeksforgeeks.org/problems/bf249fb32af71fc4e294b123d99e668a91652be4/1#

int minOperations(int *a,int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(!pq.empty() && pq.top() < a[i]) {
                count += (a[i] - pq.top());
                pq.push(a[i]);
                pq.pop();
            }
            pq.push(a[i]);
        }
        return count;
    }
