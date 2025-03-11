#include<stdio.h>
#include "apc.h"


void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    }
	printf("\n");
}

void print_list_sub(Dlist *head, int sign)
{
	/* Cheking the list is empty or not */

	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
		if(sign == 1)
	       printf("- ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    }
	printf("\n");
}