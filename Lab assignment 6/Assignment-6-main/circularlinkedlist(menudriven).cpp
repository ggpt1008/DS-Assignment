#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertbeg(int x)
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
		newnode->next=head;
		head=newnode;
		temp->next=head;	
	}
}
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
void insertafter(int x,int y)
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
		while(temp->next!=head&&temp->data!=y)
		{
			temp=temp->next;
		}
		if(temp->data!=y)
		cout<<endl<<"Node not found";
		else if(temp->data==y)
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
}
void insertbefore(int x,int y)
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
		struct node *temp=head,*prev=head;
		while(temp->next!=head&&temp->data!=y)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp->data!=y)
		cout<<endl<<"Node not found";
		else if(temp->data==y&&temp!=head)
		{
			newnode->next=temp;
			prev->next=newnode;
		}
		else
		{
			newnode->next=temp;
			struct node*temp1=head;
			while(temp1->next!=head)
			{
				temp1=temp1->next;
			}
			temp1->next=newnode;
			head=newnode;
		}
	}
}
void deletefirst()
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	else
	{
		struct node *temp=head,*temp1=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		head=head->next;
		temp->next=head;
		delete(temp1);
	}
}
void deletelast()
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	else
	{
		struct node *temp=head,*prev=head;
		while(temp->next!=head)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=head;
		delete(temp);
	}
}
void deleteany(int x)
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	else
	{
		struct node *temp=head,*prev=head;
		while(temp->next!=head&&temp->data!=x)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp->data!=x)
		cout<<endl<<"Node not found";
		else if(temp->data==x&&temp->next!=head&&temp!=head)
		{
			prev->next=temp->next;
			delete(temp);
		}
		else if(temp->next==head)
		{
			prev->next=head;
			delete(temp);
		}
		else if(temp==head)
		{
		struct node *temp2=head,*temp1=head;
		while(temp2->next!=head)
		{
			temp2=temp2->next;
		}
		head=head->next;
		temp2->next=head;
		delete(temp1);
		}
	}
}
void search(int x)
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	else
	{
		int pos=0;
		struct node *temp=head;
		while(temp->next!=head&&temp->data!=x)
		{
			pos++;
			temp=temp->next;
		}
		if(temp->data!=x)
		cout<<endl<<"Element not found";
		else
		cout<<endl<<"Element "<<x<<" found at position "<<pos+1;
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
	cout<<endl<<"Elements in the list are:"<<endl;
	while(temp->next!=head)
	{
		cout<<endl<<temp->data;
		temp=temp->next;
	}
	cout<<endl<<temp->data;
}
int main()
{
	int n,i,a,c=1;
  while(c>=1&&c<=9)
  {
	cout<<endl<<endl<<endl<<"1.Insertion at beginning";
	cout<<endl<<"2.Insertion at end";
	cout<<endl<<"3.Insertion before a node";
	cout<<endl<<"4.Insertion after a node";
	cout<<endl<<"5.Delete first node";
	cout<<endl<<"6.Delete last node";
	cout<<endl<<"7.Delete any node";
	cout<<endl<<"8.Search a node";
	cout<<endl<<"9.Display the list";
	cout<<endl<<"Choose the operation to be performed from above:";
	cin>>c;
	cout<<endl;
	if(c==1)
	{
	cout<<endl<<"Enter how many elements to be inserted in front:";
	cin>>n;
	cout<<"Enter the elements of the linked list:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a;
		insertbeg(a);
	}
    }
    if(c==2)
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
	int k,l;
	if(c==3)
	{
	cout<<endl<<"Enter the element before which you want to insert the new element:";
	cin>>k;
	cout<<"Enter the element to be inserted:";
	cin>>l;
	insertbefore(l,k);
    }
    if(c==4)
    {
	cout<<endl<<"Enter the element after which you want to insert the new element:";
	cin>>k;
	cout<<"Enter the element to be inserted:";
	cin>>l;
	insertafter(l,k);
    }
    if(c==5)
    {
	cout<<endl<<"List after deleting the first node:"<<endl;
	deletefirst();
    }
    if(c==6)
    {
	cout<<endl<<"List after deleting the last node:"<<endl;
	deletelast();
	}
	int p;
	if(c==7)
	{
	cout<<endl<<"Enter the node you want to delete:";
	cin>>p;
	deleteany(p);
    }
	int f;
	if(c==8)
	{
	cout<<endl<<"Enter the element you want to find:";
	cin>>f;
	search(f);
    }
    if(c==9)
    {
    	display();
	}
	if(c<1||c>9)
	break;
  }
}