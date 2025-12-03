#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
};
struct node* head=NULL;
void insertend(int x)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	if(head==NULL)
	{
		newnode->prev=NULL;
		head=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->prev=temp;
		temp->next=newnode;
	}
}
void display()
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	struct node *temp=head;
	while(temp!=NULL)
	{
		cout<<endl<<temp->data;
		temp=temp->next;
	}
}
int size()
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return 0;
	}
	int c=0;
	struct node *temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
int main()
{
	int n,i,a;
	cout<<endl<<"Enter how many elements to be inserted in end:";
	cin>>n;
	cout<<"Enter the elements of the linked list:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a;
		insertend(a);
	}
	display();
	cout<<endl<<"Size of the list is: "<<size();
	return 0;
}