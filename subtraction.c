#include "apc.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    int borrow = 0;
 	Dlist *temp1 = *tail1;
 	Dlist *temp2 = *tail2;
     
 	while(temp1 != NULL || temp2 != NULL)
 	{
 		// to handle edge cases to fill 0 if the data is not there
 		int n1 = (temp1 != NULL)? temp1->data : 0;
 	    int n2= (temp2 != NULL) ? temp2->data : 0;
		
 		n1 -= borrow;
        
		if(n1<n2)
 		{
 			n1 += 10;
 			borrow = 1;
 		}
 		else
 		   borrow =0;
 		
 		int res = n1 - n2;
		
		
        if(insert_at_first(headR,tailR,res) == FAILURE)
 		    return FAILURE;
		
		
		if(temp1 != NULL) temp1 = temp1->prev;
 		if(temp2 != NULL) temp2 = temp2->prev;

	
 	}

 	remove_zeros(headR,tailR);
	  
	return SUCCESS;
 } 



