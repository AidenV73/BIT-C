/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include "stdio.h"  
#include "stdlib.h"  
  
struct node  
{   int data;  
    struct node * next;  
} ;  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE );  
void sortlist( PNODE, int);  
  
int main ( )  
{   int num=1;  
    PNODE head;  
  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
            sortlist( head, num);  
    }  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}  
  
/* This is an example for list. Please programme your code like it. 
sortlist( PNODE h, int num ) 
{   PNODE p; 
    p = (PNODE)malloc( sizeof(NODE) ); 
    p->data = num; 
    p->next = h->next; 
    h->next = p; 
} 
*/  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

void sortlist( PNODE h, int num ) 
{
    PNODE p; 
    p = (PNODE)malloc( sizeof(NODE) ); 
    p->data = num; 
    
    PNODE ptr = h;
    // Move to place to insert
    while (ptr -> next != NULL && ptr -> next -> data < num)
    {
        ptr = ptr -> next;
    }

    if (ptr -> next != NULL && ptr -> next -> data == num)
    {
        return;
    }

    p -> next = ptr -> next;
    ptr -> next = p;
}
