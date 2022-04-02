https://practice.geeksforgeeks.org/problems/move-all-zeros-to-the-front-of-the-linked-list/1#

void moveZeroes(struct Node **head)
{   
    vector<int> a; 
    struct Node* temp = *head;
    while(temp) {
        if(temp->data == 0) {
            a.push_back(0);
        }
        temp = temp->next;
    }
    temp = *head;
    while(temp) {
        if(temp->data != 0) {
            a.push_back(temp->data);
        }
        temp = temp->next;
    }
    temp = *head;
    int i = 0;
    while(temp) {
        temp->data = a[i++];
        temp = temp->next;
    }
    
}
