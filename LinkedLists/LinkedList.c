//This is a singly-linked List
//Firstly, Linked Lists are a dynamic data structure. Linked lists in C are implemented as a structure. Thre structure usually contains two components, Data and then a pointer or a reference with points to the next node in the sequence.
struct Node
{
	int data;
	struct Node* next;
}

//Lets learn how to build a LinkedList
//Like any step, we first initiliaze, for us we will initialize the start/head of the linked list
struct Node* head = NULL;

//Now lets look at how we would manually create a node for a linked list, essentially in C, we would create a structure object for each node, the node will initially be assigned a NULL value and then we will connect the Nodes later on.
struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
node1->data = 1;
node1->next = NULL;

struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
node1->data = 2;
node1->next = NULL;

struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
node1->data = 3;
node1->next = NULL;

//Lets link these nodes together
head = node1;
node1->next = node2;
node2->next = node3;

//Traversing a linked list
struct Node* current = head;
while(current != NULL)
{
	printf("%d", current->data);
	current = current->next;
}
//Insertion of a node in the starting
struct Node* insert_beginning(struct Node* head, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = head;
	return new_node;
}
//Insertion of a node at some position
struct Node* insert_middle(struct Node* head, int data, int position)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;

	struct Node* current = head;
	for(int i=1: i<position && current!=NULL; i++)
	{
		current = current-next;
	}

	if (current == NULL)
	{
		printf("Not a correct position\n");
		return head;
	}

	new_node->next = current-next;
	current-next = new_node;
	return head;
}
//Insertion at the end
struct Node* insert_end(struct Node* head, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->next = NULL;

	if(head==NULL)
	{
		return new_node; //in an empty list you would return the head as starting becomes the end
	}
	struct Node* current = head;
	while(current->next != NULL)
	{
		current=current->next;
	}
	current->next=new_node;
	return head;
}


//Now, since we understand how the creation of linked list works manually, let us try to automate the process of creating a linked list of 50 nodes. 
for(int i=1; i<=50; i++)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	if(new_node==NULL)
	{
		printf("Memory Allocation failure");
		return 1;
	}
	new_node->data=i;
	new_node->next=head; //So essentially, every new node is being added to the first place
	head = new_node; 
}
//Now, since the code allocates memory to linked list, we have to free that memory
current = head;
while(current != NULL)
{
	struct Node* temp = current;
	current = current->next;
	free(temp);
}


//Question: Lets write a C function to remove all occurence of "Hello" from the linked list we created above
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


