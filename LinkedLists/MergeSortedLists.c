//Merging two sorted linked lists to one sorted linked list

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* new = malloc(sizeof(ListNode));
	struct Node* prev = new;

	while(list1 != NULL && list2 != NULL)
	{
		if(current->val <= current2->val)
		{
			prev->next = L1;
			L1 = L1->next;
		}
		else()
		{
			prev->next = L2;
			L2 = L2->next;
		}
		prev = prev->next;
	}	
	if(L1 == NULL)
	{
		prev->next = L2;
	}
	if(L2 == NULL)
	{
		prev->next = L1;
	}
	struct Node* result = new->next;
	free(new);
	return result;
}
