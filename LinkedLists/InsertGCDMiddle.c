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
    struct ListNode* new_node = NULL;
    while(current != NULL && current->next != NULL)
    {
        int gcd_val = gcd(current->val, current->next->val);
        //struct ListNode* new_node = (struct ListNode*)malloc(sizeof(ListNode));
        new_node->val = gcd_val;
        new_node->next = current->next;
        current->next = new_node;
        current = current->next->next;
    }
    return head;
}
