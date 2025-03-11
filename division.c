#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[])
{
	/* Definition goes here */
	int count=0;
    
	if(*head2 == NULL)
	  return FAILURE;

	while(subc(head1,tail1,head2,tail2) == 1)
	{
		if(subtraction(head1,tail1,head2,tail2,headR,tailR) == FAILURE)
		   return FAILURE;
	        
		count++;

        if(delete_list(head1,tail1) == FAILURE)
		  return FAILURE;

		*head1 = *headR;
		*tail1 = *tailR;

		remove_zeros(head1,tail1);

		*headR =  NULL;
		*tailR = NULL;
		

	}
	//printf("%d\n",count);
	return count;  // returning the total count 
	
	
}
