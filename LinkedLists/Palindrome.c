struct ListNode* ReverseList(struct ListNode* head)
{
    struct ListNode* next_node = NULL;
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    while(current != NULL)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}
struct ListNode* MiddleList(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* current = head;
    while(fast != NULL)
    {
        fast = current->next->next;
        slow = current->next;
    }
    return slow;
}
bool isPalindrome(struct ListNode* head){
    if(head==NULL || head->next == NULL)
    {
        return (true);
    }
    struct ListNode* Half = MiddleList(head);
    struct ListNode* Reverse = ReverseList(Half);
    struct ListNode* current = head;
    while(ReverseList != NULL)
    {
        if(Reverse->val != current->val)
        {
            return (false);
        }
        current = current->next;
        Reverse = Reverse->next;
    }
    return true;

}
