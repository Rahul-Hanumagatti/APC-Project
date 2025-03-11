#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"

int main(int argc, char *argv[])
{
	/* Declare the pointers */
      
	    Dlist *head1=NULL, *tail1=NULL;
        Dlist *head2=NULL, *tail2=NULL; 
        Dlist *headR=NULL,*tailR=NULL;

    if(argc == 4) // validation of argument count i.e, argc must be equal to 4
	{
        // validation of arguments i.e, *argv[]
		if(read_and_validate_args(argv) == SUCCESS)
		    printf("Validation of the Arguments Successfull\n");
		else
		{
			printf("Validation Unsuccessfull\n");
		    return FAILURE;
		}

	}
	else
	{
       printf("Invalid argument count\n");
	   return FAILURE;
	}
      
	  char operator = *argv[2];
		switch (operator)
		{
			case '+':
			        printf("You are performing Addition Operation\n");
                    digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the addition operation */
                     addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);

                     printf("Result is : ");
					 print_list(headR);
				break;
			case '-':
			        printf("You are performing Subtraction Operation\n");	
			       int sign = digit_to_list_sub(&head1,&tail1,&head2,&tail2,argv);
				   if(sign == -1)  // if both operands are same
				   {
					 printf("Result is : ");
                     printf("%d",0);
					 printf("\n");
					 break;
				   }
				    
				/* call the function to perform the subtraction operation */
				   subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                   
                      printf("Result is : ");
				      print_list_sub(headR,sign);
				   
				  
				break;
			case 'x':
			       printf("You are performing Multiplication Operation\n");
			       digit_to_list(&head1,&tail1,&head2,&tail2,argv);	
				/* call the function to perform the multiplication operation */
				   multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);

				   printf("Result is : ");
				   print_list(headR);
				break;
			case '/':
			        printf("You are performing Division Operation\n");
					int n = division_calc(&head1,&tail1,&head2,&tail2,argv);
					if(n == 1)  // opr1 > opr2 i.e, division is possible
					{
						digit_to_list(&head1,&tail1,&head2,&tail2,argv);
						/* call the function to perform the division operation */
				        int count = division(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv);
				   
				        printf("Result is : ");
				        printf("%d",count);
						printf("\n");
					}
					else if(n == 0) // opr1 < opr2 i.e, division is impossible , so result is 0
					{
						printf("Result is : ");
						printf("%d",0);
						printf("\n");
						//break;
					}	
					else if(n == -1)  // both opr1 == opr2 , so result is 1
					{
						printf("Result is : ");
						printf("%d",1);
						printf("\n");
						//break;
					}
					else if(n == 2)
					{
						printf("Result is : ");
						printf("Infinity");
						printf("\n");
					}
				
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}


int read_and_validate_args(char *argv[])
{
	// Operand 1
	int i=0;
	if(argv[1] == NULL || argv[1][0] == '\0')
	  return FAILURE;

	while(argv[1][i] !='\0')
	{
		if(is_digit((argv[1][i])) == 0)
		  return FAILURE;
		i++;
	}

    // Operand 2
	int j=0;
	if(argv[3] == NULL || argv[3][0] == '\0')
	  return FAILURE;

	while(argv[3][j] !='\0')
	{
		if(is_digit((argv[3][j])) == 0)
		  return FAILURE;
		j++;
	}
    
	// Operator
	if(argv[2] == NULL || strlen(argv[2]) != 1)
	  return FAILURE;

	 char op = argv[2][0];
	if(op != '+' && op != '-' && op != 'x' && op != '/')
	  return FAILURE;

	return SUCCESS;
}

// Checking if the Operands passed are digits or not
int is_digit(char c)
{
	if(c >= '0' && c <='9')
	 return 1;
	else
	 return 0;
}
