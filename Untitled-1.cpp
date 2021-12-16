#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void Insert(struct Node **head,int position,int x)
{
    
    struct Node *p,*q,*newNode;
    newNode=new Node();
    newNode->data=x;
    p=*head;
    if(position==1)
    {
        newNode->next=p;
      
        *head=newNode;
        return;
    }
    else
    {
        int k=1;
        while(p!=NULL && k<position)
        {
            k++;
            q=p;
            p=p->next;
        }
        q->next=newNode;
        newNode->next=p;
    }
}
void Delete(struct Node **head,int position)
{
    struct Node *p,*q;
    p=*head;
  
    if(*head==NULL)
    {
        cout<<"List empty!!\n";
        return;
    }

    if(position==1)
    {
        *head=(*head)->next;
        free(p);
        return;
    }
    else
    {
        int k=1;
        while(p!=NULL && k<position)
        {
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            cout<<"Position not found!!\n";
            return;
        }
        else
        {
            q->next=p->next;
            delete(p);
        }
    }
}
void Print(struct Node **head)
{
    struct Node *p=*head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
int main()
{
    struct Node *head=NULL;
    
    Insert(&head,1,5);
    Insert(&head,1,4);
    Insert(&head,3,3);
    Insert(&head,2,2);
    Insert(&head,2,1);
    Print(&head);

    Delete(&head,1);
    Print(&head);
    Delete(&head,4);
    
    Print(&head);
    Delete(&head,4);
    Print(&head);
}