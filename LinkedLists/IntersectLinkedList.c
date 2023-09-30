struct ListNode* getIntersectionNode(struct ListNode *headA, structListNode *headB)
{
	int lenA=0;
	int lenB=0;

	struct ListNode *tempA = headA, *tempB = headB;
	while(tempA != NULL)
	{
		lenA++;
		tempA = tempA->next;
	}
	while(tempB != NULL)
	{
		lenB++;
		tempB = tempB->next;
	}
	tempA = headA;
	tempB = headB;

	while(lenA>lenB)
	{
		tempA = tempA->next;
		lenA--;
	}
	while(lenB>lenA)
	{
		tempB = tempB->next;
		lenB--;
	}

	while(tempA != tempB)
	{
		tempA = tempA->next;
		tempB = tempB->next;
	}

	return(tempA);
}
