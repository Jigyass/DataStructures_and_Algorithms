struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* prev = NULL;
	struct ListNode* current = head;
	struct ListNode* next_node;

	while(current != NULL)
	{
		next_node = current->next;
		current->next = prev;
		prev = current;
		current = next_node;
	}
	return prev;
}
