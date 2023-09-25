//Given the head of singly linked list, we have to return the middle of the linked list, if there are two middle nodes, return the second value.

struct ListNode* middleNode(struct ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while(fast != NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
