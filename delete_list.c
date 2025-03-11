#include<stdio.h>
#include<stdlib.h>
#include "apc.h"

int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
      return FAILURE;

    Dlist *temp = *head;

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    while(temp != NULL)
    {
        temp = temp->next;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        free(*head);
        *head = temp;
    }

    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

// function to remove leading 0's if present
int remove_zeros(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
      return FAILURE;

    // implementing delete at 1st 
    //Dlist *temp = *head;
    while(*head != NULL && (*head)->data == 0)  // if both temp!= NULL an the current node == 0 means only it enters the loop else, ignores
    {
           if((*head)->next == NULL && (*head)->data == 0)
              return SUCCESS;
          
            // implementing delete at 1st 
           Dlist *temp = *head;
           *head = (*head)->next; // head points to next node
           free(temp);  // deleting the node with 0

           if(*head != NULL)
             (*head)->prev = NULL;  // updating 2nd node->prev = NULL to make it as 1st node
        
        temp = temp->next;
    }

    if(*head == NULL)
       *tail = NULL;
     

    return SUCCESS;

}