#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *headR2=NULL,*tailR2=NULL;
	Dlist *headBK=NULL,*tailBK=NULL;
    
	Dlist *temp2 = *tail2; int carry =0, count =0;
	while(temp2 != NULL)
	{
		int n2 = temp2->data;
        
		Dlist *temp1 = *tail1;
		carry =0;
        
		// inserting no of 0's as per the count in R2 list after each traversal of temp2 
		for(int i=0;i<count;i++)
		{
           if(insert_at_first(&headR2,&tailR2,0) == FAILURE)
		     return FAILURE;
		}
	
		while(temp1 != NULL)
		{
			int n1 = temp1->data;
		
			int res = n1 * n2 + carry;
			
		    carry = res/10;

			int data = res%10;

			if(insert_at_first(&headR2,&tailR2,data) == FAILURE)
				return FAILURE;

	
			temp1 = temp1->prev;
		}

		if(carry >0)
		{
			if(insert_at_first(&headR2,&tailR2,carry) == FAILURE)
				return FAILURE;
			
		}

		if(*headR == NULL)  // 1st digit's answers
		{
			*headR = headR2;
			*tailR = tailR2;
			headR2 = tailR2 = NULL;

		}
		else  // if both headR and headR2 != NULL 
		{
            if(addition(headR,tailR,&headR2,&tailR2,&headBK,&tailBK) == FAILURE)
		       return FAILURE;

			if(delete_list(headR,tailR) == FAILURE)
			  return FAILURE;
			if(delete_list(&headR2,&tailR2) == FAILURE)
			  return FAILURE;

            // updating headBK i.e, added result in headBk in headR
			*headR = headBK;
			*tailR = tailBK;
			
            // making headBK as NULL to store next node's addition  result
			headBK = tailBK = NULL;

		}

		temp2 = temp2->prev;
		count++;
		
	}

	remove_zeros(headR,tailR);

	return SUCCESS;
}

