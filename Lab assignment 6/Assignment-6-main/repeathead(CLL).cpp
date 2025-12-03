#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertend(int x)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=head;
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
	cout<<endl<<"Displaying the list with repeating head node:";
	while(temp->next!=head)
	{
		cout<<endl<<temp->data;
		temp=temp->next;
	}
	cout<<endl<<temp->data;
	cout<<endl<<temp->next->data;
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
}