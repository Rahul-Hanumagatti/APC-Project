/*
q
q
me:Krishna
Date :
Description :
Sample input :
Sample output :
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"

int sign =0;

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    // / * run a loop for argc -1 times * /
    // / * First operand * /

    // / * Store the argv[1] into an char pointer * /
	// char *str=agrv[1];
    // / * Run a loop from str[i] != '\0' * /
	// / * get one by one char and convert that into an digit * /
	// create a node and store the data 
	// / * by call insert at last function * /

    //  / * Second operand * /
    //  / * do the same steps * /

       // converting 1st operand from string into integer and storing it into list1
        char *str1 = argv[1];
        int i=0, n1=0, n2=0;
        while(str1[i]!= '\0')
        {
            n1 = str1[i] - 48; // converting string into integer by subtracting with 0
            insert_at_last(head1,tail1,n1);  // adding converted digit to list1 i.e, insert at last
        
            i++;
        }
        print_list(*head1);

        // converting 2nd operand from string into integer and storing it into list2
        char *str2 = argv[3];
        int j=0;
        while(str2[j]!= '\0')
        {
            n2 = str2[j] - 48;  // converting string into integer by subtracting with 0
            // insert at last because we are converting 1st digit and it should be 1st and next digits should be next to it 
            insert_at_last(head2,tail2,n2); // adding converted digit to list2 i.e, insert at last

            j++;
        }
        print_list(*head2);
    
}

int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));
    if(newnode == NULL)
      return FAILURE;

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    if(*head == NULL)
    {
        *head = *tail = newnode;
        return SUCCESS;
    }

    newnode->prev = *tail;
    (*tail)->next = newnode;
    *tail = newnode;
    return SUCCESS;
    
}

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));
    if(newnode == NULL)
      return FAILURE;

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = *tail = newnode;
        return SUCCESS;
    }

    (*head)->prev = newnode;
    newnode->next = *head;
    *head = newnode;
    return SUCCESS;
}

int digit_to_list_sub(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    int sign = 0;
    
    // if(strcmp(argv[3],0) == 0)
    //   return 2;
    // taking length of both the strings 
    int l1 = strlen(argv[1]);
    int l2 = strlen(argv[3]);
    
    int i=0, n1=0, n2=0;
    
    if(l1>l2)
    {
        char *s1 = argv[1];
        char *s2 = argv[3];
        while(s1[i] !='\0')
        {
            n1 = s1[i] - 48;
            insert_at_last(head1,tail1,n1);
            i++;
        }
        
        int j=0;
        while(s2[j] != '\0')
        {
            n2 = s2[j] - 48;
            insert_at_last(head2,tail2,n2);
            j++;
        }
        return sign;
    }
    else if(l1<l2)
    {
        char *s1 = argv[3];
        char *s2 = argv[1];
        while(s1[i] !='\0')
        {
            n1 = s1[i] - 48;
            insert_at_last(head1,tail1,n1);
            i++;
        }
        
        int j=0;
        while(s2[j] != '\0')
        {
            n2 = s2[j] - 48;
            insert_at_last(head2,tail2,n2);
            j++;
        }
        sign =1;
        return sign;
    }
    else if(l1 == l2)
    {
        int cmp =strcmp(argv[1],argv[3]); 
        if(cmp > 0)
        {
            char *s1 = argv[1];
            char *s2 = argv[3];
    
           while(s1[i] !='\0')
           {
              n1 = s1[i] - 48;
              insert_at_last(head1,tail1,n1);
              i++;
           }
        
          int j=0;
          while(s2[j] != '\0')
          {
            n2 = s2[j] - 48;
            insert_at_last(head2,tail2,n2);
            j++;
          }
          sign =0;
          return sign;

        }
        else if(cmp <0)
        {
           char *s1 = argv[3];
           char *s2 = argv[1];
           while(s1[i] !='\0')
           {
             n1 = s1[i] - 48;
             insert_at_last(head1,tail1,n1);
             i++;
           }
        
          int j=0;
           while(s2[j] != '\0')
           {
            n2 = s2[j] - 48;
            insert_at_last(head2,tail2,n2);
            j++;
           }
          sign =1;
          return sign;

        }
        else if(cmp == 0)
        {
          return sign = -1;
        }
    }
      

}

int division_calc(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    int l1 = strlen(argv[1]);
    int l2 = strlen(argv[3]);

    if((strcmp(argv[3],"0")) ==0)
      return 2;

    if(l1 > l2)  // Division is possible
    {
        return 1;
    }
    else if(l1 < l2) // division is impossible
    {
        return 0;
    }
    else if(l1 == l2)  // if both lengths are same means, comparing them 
    {
        int cmp = strcmp(argv[1],argv[3]);
        if(cmp > 0)  // opr1>opr2 i.e, division is possible
          return 1;
        else if(cmp < 0)  // opr1<opr2 i.e, division is impossible
          return 0;
        else if(cmp == 0)  // both are same
          return -1;
    }

}

int subc(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int count1= 0 , count2 =0;
    Dlist *temp1 = *head1, *temp2 = *head2;
    while(temp1!= NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    // printf("count1 = %d\n",count1);
    // printf("count2 = %d\n",count2);
    

    if(count1 > count2)
      return 1;
    else if(count1 < count2)
      return 0;
    else if(count1 == count2)
    {
        temp1 = *head1;
        temp2 = *head2;
      
       for(int i=1; i <= count1; i++)
       {
            if(temp1->data > temp2->data)
              return 1;
            else if(temp1->data < temp2->data)
               return 0;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return 1; // if both are same
    
    

}
