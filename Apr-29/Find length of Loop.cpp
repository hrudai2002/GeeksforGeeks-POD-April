int countNodes(Node* node, Node* curr) {
    int count = 1;
    while(curr != node) {
        count += 1;
        curr = curr->next;
    }
    return count;
}
int countNodesinLoop(struct Node *head)
{
   unordered_map<Node*, int> mp;
   Node* node = head;
   while(node) {
       if(mp.find(node) != mp.end()) {
           return countNodes(node, node->next);
       }
       else {
           mp[node] = 1;
       }
       node = node->next;
   }
   return 0;
}
