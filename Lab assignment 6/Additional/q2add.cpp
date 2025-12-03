
#include<iostream>
using namespace std;
void deleteany(int x);
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
struct nodes
{
	int d;
	struct nodes *next,*prev;
};
struct nodes *head1=NULL;
void insertend(int x)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(head==NULL)
	{
		head=newnode;
		newnode->link=head;
	}
	else
	{
		struct node *temp=head;
		while(temp->link!=head)
		{
			temp=temp->link;
		}
		temp->link=newnode;
		newnode->link=head;
	}
}
void insertend1(int x)
{
	struct nodes *newnode1=(struct nodes*)malloc(sizeof(struct nodes));
	newnode1->d=x;
	newnode1->next=NULL;
	if(head1==NULL)
	{
		newnode1->prev=NULL;
		head1=newnode1;
	}
	else
	{
		struct nodes *temp1=head1;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		newnode1->prev=temp1;
		temp1->next=newnode1;
	}
}
void parity()//circular linked list
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	int j,sum;
	struct node *temp=head,*nextnode;
	while(temp->link!=head)
	{
		sum=0;
		j=temp->data;
		while(j>0)
		{
			sum=sum+j%2;
			j=j/2;
		}
		if(sum%2==0)
		{	
		nextnode=temp->link;//to store next node
		deleteany(temp->data);
		temp=nextnode;
	    }                  
	    else
		temp=temp->link;
	}
	    sum=0;
		j=temp->data;//for checking last node
		while(j>0)
		{
			sum=sum+j%2;
			j=j/2;
		}
		if(sum%2==0)
		deleteany(temp->data);
}
void deleteany(int x)//CIRCULAR LINKED LIST
{
	if(head==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	else
	{
		struct node *temp=head,*prev=head;
		while(temp->link!=head&&temp->data!=x)
		{
			prev=temp;
			temp=temp->link;
		}
		if(temp->data!=x)
		cout<<endl<<"Node not found";
		else if(temp->data==x&&temp->link!=head&&temp!=head)
		{
			prev->link=temp->link;
			delete(temp);
		}
		else if(temp->link==head)
		{
			prev->link=head;
			delete(temp);
		}
		else if(temp==head)
		{
		struct node *temp2=head,*temp1=head;
		while(temp2->link!=head)
		{
			temp2=temp2->link;
		}
		head=head->link;
		temp2->link=head;
		delete(temp1);
		}
	}
}
void deleteany1(int y)
{
	if(head1==NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	else
	{
		struct nodes *temp=head1;
		while(temp->next!=NULL&&temp->d!=y)
		{
			temp=temp->next;
		}
		if(temp->d!=y)
		{
			cout<<endl<<"Element not found";
			return;
		}
		else
		{
			if(temp->prev==NULL&&temp->d==y)
			{
				head1=temp->next;
				temp->next->prev=NULL;
				free(temp);
			}
			else if(temp->next==NULL&&temp->d==y)
			{
				temp->prev->next=NULL;
				free(temp);
			}
			else if(temp->next==NULL&&temp->prev==NULL&&temp->d==y)
			{
				head1=NULL;
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
void parity1()//doubly linked list 
{
	if(head1==NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	int j,sum;
	struct nodes *temp=head1,*nextnode;
	while(temp!=NULL)
	{
		sum=0;
		j=temp->d;
		while(j>0)
		{
			sum=sum+j%2;
			j=j/2;
		}
		if(sum%2==0)
		{	
		nextnode=temp->next;//to store next node
		deleteany1(temp->d);
		temp=nextnode;
	    }                  
	    else
		temp=temp->next;
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
	while(temp->link!=head)
	{
		cout<<endl<<temp->data;
		temp=temp->link;
	}
	cout<<endl<<temp->data;
}

void display1()
{
	if(head1==NULL)
	{
		cout<<endl<<"Empty list";
		return;
	}
	struct nodes *temp=head1;
	while(temp!=NULL)
	{
		cout<<endl<<temp->d;
		temp=temp->next;
	}
}
int main()
{
	int n,i,a,c=1;
  while(c>=1&&c<=6)
  {
	cout<<endl<<endl<<endl<<"1.Insertion at end of circular linked list";
	cout<<endl<<"2.Insertion at end of doubly linked list";
	cout<<endl<<"3.Remove elements with Parity= even from circular linked list";
	cout<<endl<<"4.Remove elements with Parity= even from doubly linked list";
	cout<<endl<<"5.Display the circular linked list";
	cout<<endl<<"6.Display the doubly linked list";
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
	cout<<endl<<"Enter how many elements to be inserted in end:";
	cin>>n;
	cout<<"Enter the elements of the linked list:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a;
		insertend1(a);
	}
    }
    if(c==3)
    {
    	parity();
	}
	if(c==4)
    {
    	parity1();
	}
	if(c==5)
	{
		display();
	}
	if(c==6)
	{
		display1();
	}
	if(c<1||c>6)
	break;
    }
}
