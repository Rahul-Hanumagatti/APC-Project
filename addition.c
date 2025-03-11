#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"
//#include <stddef.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	// /* Definition goes here */
    // 	/ * 67 + 12 ( both equal ) * /
	// / * 88 + 12 ( carry ) * /
	// / * 88 + 2 ( 2nd_opernad < 1st_opernad ) * /
	// / * 2 + 88 ( 1st_operand < 2nd_opernad ) * /

	// (i) => temp1 != NULL || temp2 != NULL 
	// {
	//     (ii) => temp1 != NULL && temp2 != NULL 
	
	// 	(iii) temp1 != NULL && temp2 == NULL 

	// 	(iv) temp1 == NULL && temp2 != NULL 
	// }
	// carry == 1 
	// { 
	//     / * add * /
	// 	/ * reset carry with 0 * /
    // }

   Dlist *temp1 = *tail1, *temp2 = *tail2;
   int sum=0, data=0, carry=0;

   while(temp1 !=NULL || temp2 !=NULL)
   { 
	 int n1 = (temp1 != NULL)? temp1->data : 0;
	 int n2= (temp2 != NULL) ? temp2->data : 0;

      sum = n1 + n2 + carry;
	   //carry = 0;
	   data = sum%10; // get last digit
       
	   // insert at first because we are adding the last digits so inserting that digit first for every iteration
	   if(insert_at_first(headR, tailR, data) == FAILURE) // inserting last digit at first
	      return FAILURE;

	   carry = sum/10; // removes last digit and contains only 1st digit i.e, carry

	   if(temp1 != NULL) temp1 = temp1->prev;
	   if(temp2 != NULL) temp2 = temp2->prev;
   }

   if(carry > 0) // if carry remains means, inserting carry into headR i.e result list
   {
	 if(insert_at_first(headR, tailR, carry) == FAILURE) // inserting last digit
	    return FAILURE;
   }

   remove_zeros(headR,tailR);

   return SUCCESS;

}
