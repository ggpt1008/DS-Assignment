#include<iostream>
using namespace std;
struct node
{
	char data;
	struct node *next,*prev;
};
struct node* head=NULL;
void insertend(char x)
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
void check()
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	struct node *temp=head,*temp1=head;
	int c=0,z=0,k=0;
	while(temp->next!=NULL)
	{
		c++;
		temp=temp->next;
	}
	while(z!=c/2)
	{
		z++;
		if(temp1->data==temp->data)
		{
			temp1=temp1->next;
			temp=temp->prev;
			k++;
		}
	}
	if(k==z)
	cout<<endl<<"Its a palindrome";
	else
	cout<<endl<<"Its not a palindrome";
}
int main()
{
	int n,i;
	char a;
	cout<<endl<<"Enter how many elements to be inserted in end:";
	cin>>n;
	cout<<"Enter the elements of the linked list:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a;
		insertend(a);
	}
	display();
	check();
}