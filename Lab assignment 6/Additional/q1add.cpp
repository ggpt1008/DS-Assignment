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
void split()
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	struct node *temp=head,*head2,*temp1=head;
	int c=0,m;
	while(temp->next!=head)
	{
	   temp=temp->next;
	   c++;
    }
    if(c>0)
    {
    m=c/2;
    temp=head;
    c=0;
    while(c!=m)
    {
    	temp=temp->next;
    	c++;
	}
	while(temp1->next!=head)
	{
		temp1=temp1->next;
	}
	temp1->next=temp->next;
	temp->next=head;
	head2=temp1->next;
    temp=head;//for printing the list 1
	cout<<endl<<"Elements in the list1 are:"<<endl;
	while(temp->next!=head)
	{
		cout<<endl<<temp->data;
		temp=temp->next;
	}
	cout<<endl<<temp->data;
	temp=head2;
	cout<<endl<<"Elements in the list2 are:"<<endl;
	while(temp->next!=head2)
	{
		cout<<endl<<temp->data;
		temp=temp->next;
	}
	cout<<endl<<temp->data;
    }
    else
    cout<<endl<<"list can not be splitted";
    cout<<endl<<endl<<"Note: The first list now becomes the new original list";
}
int main()
{
	int n,i,a,c=1;
  while(c>=1&&c<=2)
  {
	cout<<endl<<endl<<endl<<"1.Insertion at end";
	cout<<endl<<"2.Split the list";
	cout<<endl<<"Choose the operation to be performed from above:";
	cin>>c;
	cout<<endl;
    if(c==1)
    {
	cout<<endl<<"Enter how many elements to be inserted in end:";
	cin>>n;
	cout<<"Enter the elements of the linked list:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a;
		insertend(a);
	}
    }
   	if(c==2)
	{
		split();
    }
	if(c<1||c>2)
	break;
  }
}