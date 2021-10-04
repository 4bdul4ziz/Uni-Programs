#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int *nullptr = NULL;

struct Node
{
	int data;
	struct Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

void push(struct Node *headRef, int data)
{
	struct Node *node = new Node(data);
	node->next = headRef;
	headRef = node;
}

void printList(string msg, struct Node *head)
{
	printf(": ");
	while (head)
	{
		printf("%d —> ", head->data);
		head = head->next;
	}
}

Node *reverse(struct Node *curr, int k)
{
	struct Node *prev = nullptr;

	while (curr && k--)
	{
		struct Node *next = curr->next;

		curr->next = prev;

		prev = curr;
		curr = next;
	}

	return prev;
}

Node *skipKNodes(struct Node *curr, int k)
{
	struct Node *prev = nullptr;

	while (curr && k--)
	{
		prev = curr;
		curr = curr->next;
	}

	return prev;
}

Node *reverseAlternatingKNodes(struct Node *head, int k)
{
	struct Node *prev = nullptr;
	struct Node *curr = head;

	while (curr)
	{
		struct Node *lastNode = curr;

		struct Node *frontNode = reverse(curr, k);

		if (!prev)
		{
			head = frontNode;
		}
		else
		{
			prev->next = frontNode;
		}

		lastNode->next = curr;

		prev = skipKNodes(curr, k);
	}
	return head;
}

int main()
{
	struct Node *head = nullptr;

	int n = 10;
	while (n)
	{
		push(head, n--);
	}

	int k = 2;

	printList("Original linked list ", head);
	head = reverseAlternatingKNodes(head, k);
	printList("Resultant linked list", head);

	return 0;
}