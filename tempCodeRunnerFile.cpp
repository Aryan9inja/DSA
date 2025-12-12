
bool isCircular(Node* head){
    Node* curr=head->next;

    while(curr!=head || curr!=NULL){
        curr=curr->next;
    }