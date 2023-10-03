struct node* delete_hello(struct node* head)
{
	struct node* current = head;
	struct node* prev = null;

	while(current != null)
	{
		if(strcmp(current->data, "hello")==0)
		{
			//check if the node is the head node, if it is, we would need to appoint the next node as the head
			if(prev==null)
			{
				struct node* temp = current;
				current = current->next;
				head = current;
				free(temp);
			}
			else
			{
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	return head;
}