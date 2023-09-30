//Merging two sorted linked lists to one sorted linked list

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	// Create a dummy node as the starting point of the merged list
    
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    	struct ListNode* prev = dummy;
	// While both linked lists are not empty
    	while (list1 != NULL && list2 != NULL) 
	{
        	if (list1->val <= list2->val) {
            	prev->next = list1;
            	list1 = list1->next;
        	} 
		else 
		{
			prev->next = list2;
            		list2 = list2->next;
        	}
        	prev = prev->next;
    	}

    // Once we reach the end of one linked list, append the other
    if (list1 == NULL) {
        prev->next = list2;
    }
    if (list2 == NULL) {
        prev->next = list1;
    }

    // Return the sorted merged list starting from the node after the dummy node
    struct ListNode* result = dummy->next;
    free(dummy); // Free the dummy node
    return result;
    }
