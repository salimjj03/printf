#include <stdio.h>
#include <stdlib.h>
struct node
{
	int a;
	struct node *next;
};

struct node *newnode(int value)
{
		struct node *newnode;

		newnode = malloc(sizeof(struct node));
		if (newnode == NULL)
		{
			return (NULL);
		}
		newnode->a = value;
		newnode->next = 0;
		return (newnode);
}

struct node *addnode(struct node *head, int value)
	{
		struct node *newnode, *tmp;

		tmp = head;
		newnode = malloc(sizeof(struct node));
		newnode->a = value;
		newnode->next = 0;
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
		tmp = tmp->next;
		return (tmp);
	}

void printnode(struct node *head)
{
	struct node *tmp;
	tmp = head;
	while (tmp->next != 0)
	{
		printf("%d %p\n", tmp->a, tmp->next);
		tmp = tmp->next;
	}
		printf("%d %p\n", tmp->a, tmp->next);
}

struct node *insertnode(struct node *head, int position, int value)
{
	struct node *tmp, *newnode;
	unsigned int i;

	tmp = head;
	i = 1;
	newnode = malloc(sizeof(struct node));
	newnode->a = value;
	while (i < position)
	{
		tmp = tmp->next;
		i++;
	}
	newnode->next = tmp->next;
	tmp->next = newnode;
	return(tmp);
}

int main(void)
{

	struct node *head;

	head = newnode(7);
	addnode(head, 77);
	addnode(head, 88);
	insertnode(head, 2, 14);
	insertnode(head, 2, 14);
	insertnode(head, 2, 14);
	insertnode(head, 2, 14);
	printnode(head);
	free(head);
	return(0);
}
