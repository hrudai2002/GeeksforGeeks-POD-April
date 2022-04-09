https://practice.geeksforgeeks.org/problems/ebb840c27b36a8c8ad121fd576a2fa6f2bc1e6f2/1#

int sum_at_distK(Node* root, int target, int k)
    {
       unordered_map<Node*, Node*> parent;
       unordered_set<Node*> vis;
       parent[root] = NULL;
       
       queue<Node*> q;
       q.push(root);
       Node* target_node = NULL;
       while(!q.empty()) {
           Node* node = q.front();
           q.pop();
           if(node->data == target) {
               target_node = node;
           }
           if(node->left) {
               parent[node->left] = node;
               q.push(node->left);
           }
           if(node->right) {
               parent[node->right] = node;
               q.push(node->right);
           }
       }
       int ans = 0;
       queue<Node*> que;
       que.push(target_node);
       que.push(NULL);
       while(!que.empty() && k >= 0) {
           Node* node = que.front();
           que.pop();
           if(node == NULL) {
               if(!que.empty()) que.push(NULL);
               k--;
           }
           else {
               vis.insert(node);
               if(parent[node] != NULL && vis.find(parent[node]) == vis.end()) {
                   que.push(parent[node]);
               }
               if(node->left != NULL && vis.find(node->left) == vis.end()) {
                   que.push(node->left);
               }
               if(node->right != NULL && vis.find(node->right) == vis.end()) {
                   que.push(node->right);
               }
           }
       }
       for(auto i : vis)
        ans += i->data;
       return ans;
    }
