#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR, char *argv[]);

/* Read and Validate Command Line Arguments*/
int read_and_validate_args(char *argv[]);

/*Checking the argument passed is digit or not*/
int is_digit(char c);

int insert_at_last(Dlist **head, Dlist **tail, int data);

int insert_at_first(Dlist **head, Dlist **tail, int data);

void print_list(Dlist *head);

int digit_to_list_sub(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

void print_list_sub(Dlist *head, int sign);

int delete_list(Dlist **head, Dlist **tail);

int remove_zeros(Dlist **head, Dlist **tail);

int division_calc(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

int subc(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
#endif
