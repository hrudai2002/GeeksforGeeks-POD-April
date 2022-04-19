https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1

struct Node* partition(struct Node* head, int x) {
    vector<int> a;
    int i = 0;
    Node* temp = head;
    while(temp) {
        if(temp->data < x) 
        a.push_back(temp->data); 
        temp = temp->next;
    }
    temp = head;
    while(temp) {
        if(temp->data == x) 
        a.push_back(temp->data); 
        temp = temp->next;
    }
    temp = head;
    while(temp) {
        if(temp->data > x) 
        a.push_back(temp->data); 
        temp = temp->next;
    }
    temp = head;
    while(temp) {
        temp->data = a[i++];
        temp = temp->next;
    }
    return head;
    
}
