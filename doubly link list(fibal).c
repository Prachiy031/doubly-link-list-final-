/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct abc
{
  char name[20];
  int prn;
  struct abc *prv;
  struct abc *next;
};
void inserts(struct abc *);  //function declaration
void insertm(struct abc*);
void deletem(struct abc*);
struct abc* deletep(struct abc*);  //returning pointer
void deletes(struct abc*);
void count(struct abc*);
void rev(struct abc*);
void display(struct abc*);

void main()
{
   int ch,y;     //choice and y for executing again or not
   struct abc *head;              //first node(here head is local as previously it was global in singly link list)
   head = (struct abc *)malloc(sizeof(struct abc));     //thats why not gonna pass data we gonna pass head address to each function
   printf("Enter name and prn no. of president :\n");
   scanf(" %s",head->name);
   scanf("%d",&head->prn);
   
   head->prv = NULL;
   head->next = NULL;
   inserts(head);   //function calling
   struct abc *temp;
   temp = head;
   
   do
   {
     printf("Enter choice:\n");
     printf("1.insert member\n");
     printf("2.delete member\n");
     printf("3.delete president\n");
     printf("4.delete secretary\n");
     printf("5.count no. of nodes:\n");
     printf("6.reverse the link\n");
     printf("7.display\n");
     printf("8.exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:
                insertm(head);
                break;
              
         case 2:
                deletem(head);
                break;
         case 3:
                head = deletep(head);
                //deletep(head);
                break;
         case 4:
                deletes(head);
                break;
                
         case 5:
                count(head);
                break;
                
         case 6:
         while(temp->next !=NULL)
         {
             temp = temp->next;
             
         }
                rev(temp);
                break;
                
         case 7:
                display(head);
                break;
                
         case 8:
               exit;
         default : 
               printf("wrong choice\n");      
     }
     printf("\nDo you want to continue?\n");
     scanf("%d",&y);
     
   }
   while(y==1);
  
}
void inserts(struct abc *head)
{
   
   struct abc *new;             //last node
   new = (struct abc *)malloc(sizeof(struct abc));
   printf("Enter name and prn no. of secretary :\n");
   scanf(" %s",new->name);
   scanf("%d",&new->prn);
   
   new->prv = NULL;
   new->next = NULL;
   
   head->next = new;
   new->prv = head;
   
}
void insertm(struct abc* head)
{
    struct abc *new,*temp;
    new = (struct abc *)malloc(sizeof(struct abc));
    printf("Enter name and prn no. of member :\n");
   scanf(" %s",new->name);
   scanf("%d",&new->prn);
   temp = head->next;  //last node as temp
   
   new->prv = NULL;
   new->next = NULL;
   new->next = head->next;
   new->prv = head;
   head->next = new;
   new->prv = head;
   new->next = temp;
   temp->prv = new;
}
struct abc* deletep(struct abc* head)
{
   struct abc *temp;
   temp = head;
   head = head->next;
   free(temp);
   return head;
}
void deletes(struct abc* head)
{
    struct abc *temp,*prv;
   // temp = head;
  //  head = head->next;
  //  head->prv = NULL;
    while(temp->next!= NULL)
    {
        temp->prv = temp;
        temp = temp->next;
    }
    temp->prv->next = NULL;
    free(temp);
}
void deletem(struct abc* head)
{
    struct abc *temp;
    temp = head->next;
    head->next = temp->next;
    temp->next->prv = head;
    free(temp);
    
}

void count(struct abc *head)
{
    int i=0;
    struct abc *temp;
    temp = head;
    while(temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    printf("Count of nodes are: %d",i);
}
void display(struct abc *head)
{
    struct abc *temp = head;
    while(temp!= NULL)
    {
        printf("Name : %s\t PRN : %d\n",temp->name,temp->prn);
        temp = temp->next;
    }
}

void rev(struct abc *temp)
{
    if(temp!=NULL)
    {
        printf("\n%s %d",temp->name,temp->prn);
        temp = temp->prv;
        rev(temp);
    }
}

    
