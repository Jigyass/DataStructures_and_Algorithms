 int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* current = head;
    //struct ListNode new_node = NULL;
   
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    while(current!=NULL && current->next!=NULL)
    {
        struct ListNode* new_node =(struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* temp = current->next;
        int gcd_val = gcd(current->val, temp->val);
        new_node->val = gcd_val;

        current->next = new_node;
        new_node->next = temp;
        current = current->next->next;
        
    }
    return head;
}
