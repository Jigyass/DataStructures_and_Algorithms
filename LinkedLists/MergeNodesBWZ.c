struct ListNode* mergeNodes(struct ListNode* head){
    head = head->next; //Because first node will always be zero
    struct ListNode* current = head;
    while(current != NULL)
    {
        int sum=0;
        struct ListNode* temp = current;
        while(temp->val != 0)
        {
            sum+=temp->val;
            temp = temp->next; 
        }
        current->val = sum;
        current->next = temp->next;
        current = current->next;
    }
    return head;

}
