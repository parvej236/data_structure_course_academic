#include <bits/stdc++.h>
using namespace std;
                     
#define endl '\n' 
#define optimize() std::ios_base::sync_with_stdio(0); cin.tie(0);
           
class Node {
 public:
 int value;
 Node * next;
 Node (int value)
 {
    this->value=value;
    this->next=NULL;
 }
};

void display(Node * head)
{
    Node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
                     
void insert_at_head(Node *&head, int value)
{
    Node *newNode=new Node(value);
    newNode->next=head;
    head=newNode;


}

void insert_at_tail(Node *&head,Node *&tail, int value)
{
    Node *newNode= new Node(value);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return ;
    }
    tail->next=newNode;
    tail=newNode;
}
void insert_at_any_positon(Node *head, int pos, int value)
{
    Node *newNode= new Node(value);
    Node *temp=head;
    for(int i=1; i<pos-1; i++)
    {
        temp=temp->next;

    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void delete_at_any_pos(Node *&head, int pos)
{
        Node *temp=head;
        for(int i=0; i<pos-1; i++)
        {
            temp=temp->next;
        }
        Node *deleteNode=temp->next;
        temp->next=temp->next->next;
        delete(deleteNode);
    
}

void input_singly_linked_list(Node *&head, Node*&tail, int value)
{
    Node *newNode=new Node(value);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    tail->next=newNode;
    tail=newNode;


}
void recursive_print(Node *x)
{
    if(x==NULL)
    {
        return ;
    }
    cout<<x->value<<" ";
    recursive_print(x->next);
}

void recursive_print_reverese(Node *x)
{
    if(x==NULL)
    {
        return;
    }
    recursive_print_reverese(x->next);
    cout<<x->value<<" ";

}
int main() {
    optimize();
  
       


   Node *head=NULL;
   Node *tail=NULL;
   int val;
   while(true)
   {
    cin>>val;
    if(val==-1)
    {
        break;
    }
    input_singly_linked_list(head,tail,val);
    
   }
    

  
   
    
      
      // insert_at_head(head,50);
     // insert_at_tail(head,tail,60);
    // insert_at_any_positon(head,3,60);
    // delete_at_any_pos(head,4);
    recursive_print(head);
    cout<<endl;
    recursive_print_reverese(head);
    cout<<endl;

     display(head);
                     
                     
                     
                     
    return 0;
}