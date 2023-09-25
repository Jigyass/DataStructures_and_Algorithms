//Imagine you are given a singly linked list. Each node of the list contains a 0 or 1 value. Return the decimal value of the linked list.

int Decimal_value(struct Node* head)
{
	int decimal=0;
	struct Node* current = head;
	while(current !=NULL)
	{
		decimal = decimal << 1 | current->data;
		current = current->next;
	}
	return decimal;
}
