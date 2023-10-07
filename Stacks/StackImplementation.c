#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackNode
{
	int data;
	struct StackNode* next;
};

struct Stack{
	struct StackNode* top;
}

struct Stack* createStack()
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = NULL;
	return stack;
}

bool isEmpty(struct Stack* stack)
{
	return (stack->top == NULL);
}

void push(struct Stack* stack, int data)
{
	struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("stack is empty\n");
		return -1;
	}
	struct StackNode* temp = stack->top;
	int poppedData = temp->data;
	stack->top = temp->next;
	free(temp);
	return poppedData;
}

int peek(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is Empty\n");
		return -1;
	}
	return stack->top->data;
}

