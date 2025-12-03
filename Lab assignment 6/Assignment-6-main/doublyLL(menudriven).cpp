#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
};
struct node* head=NULL;
void insertbeg(int x)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->prev=NULL;
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}
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
void insertbefore(int x,int y)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(head==NULL)
	{
		newnode->prev=NULL;
		newnode->next=NULL;
		head=newnode;
		return;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL&&temp->data!=y)
		{
			temp=temp->next;
		}
		if(temp->data!=y)
		{
			cout<<endl<<"Node not found";
			return;
		}
		else 
		{
			if(temp->prev==NULL)
			{
				newnode->next=temp;
				temp->prev=newnode;
				newnode->prev=NULL;
				head=newnode;
			}
			else 
			{
				temp->prev->next=newnode;
				newnode->prev=temp->prev;
				temp->prev=newnode;
				newnode->next=temp;
			}
		}
	}
}
void insertafter(int x,int y)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(head==NULL)
	{
		newnode->prev=NULL;
		newnode->next=NULL;
		head=newnode;
		return;
	}
	else
	{
		struct node *temp=head;
		while(temp!=NULL&&temp->data!=y)
		{
			temp=temp->next;
		}
		if(temp->data!=y)
		{
			cout<<endl<<"Node not found";
		}
		else
		{
			if(temp->next==NULL)
			{
				temp->next=newnode;
				newnode->next=NULL;
				newnode->prev=temp;
			}
			else
			{
				newnode->next=temp->next;
				temp->next->prev=newnode;
				temp->next=newnode;
				newnode->prev=temp;
			}
		}
	}
}
void deletefirst()
{
	if(head==NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	else
	{
		struct node* temp=head;
		if(temp->next==NULL)
		{
			head=NULL;
			free(temp);
			return;
		}
		head=temp->next;
		temp->next->prev=NULL;
		free(temp);
	}
}
void deletelast()
{
	if(head==NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	else
	{
		struct node* temp=head;
		if(temp->next==NULL)
		{
			head=NULL;
			free(temp);
			return;
		}
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
	}
}
void deleteany(int y)
{
	if(head==NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL&&temp->data!=y)
		{
			temp=temp->next;
		}
		if(temp->data!=y)
		{
			cout<<endl<<"Element not found";
			return;
		}
		else
		{
			if(temp->prev==NULL&&temp->data==y)
			{
				head=temp->next;
				temp->next->prev=NULL;
				free(temp);
			}
			else if(temp->next==NULL&&temp->data==y)
			{
				temp->prev->next=NULL;
				free(temp);
			}
			else if(temp->next==NULL&&temp->prev==NULL&&temp->data==y)
			{
				head=NULL;
				free(temp);
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
			}
		}
	}
}
void search(int k)
{
	if(head==NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	else
	{
		int pos=0;
		struct node *temp=head;
		while(temp!=NULL&&temp->data!=k)
		{
			temp=temp->next;
			pos++;
		}
		if(temp->data!=k)
		{
			cout<<endl<<"Element not found";
			return;
		}
		else
		{
			cout<<endl<<"Element "<<k<<" found at position "<<pos+1;
		}
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
	deletefirst();
    }
    if(c==6)
    {
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