#include "DList.h"
#include <iostream>

using namespace std;


DList::DList()
{
    createDummyHead();
}

DList::~DList()
{
    //Clear The list
    Clear();
    //Delete Dummy Node
    //Write your code between these lines only
    //---------------------------
    delete head;
    //---------------------------
}

// copy constructor
DList::DList(const DList& other)
{
    //Initialize current list
    createDummyHead();
    //Check if other list is empty (if empty do nothing)
    if(other.empty())
        return;
    //Iterate through all the nodes of other list
    //and add all data elements to current list
    Nodeptr other_curr = other.head->next;
    Nodeptr other_head = other.head;

    //Write your code between these lines only
    //---------------------------
    while(other_curr!=other_head)
    {
        addTail(other_curr->data);
        other_curr=other_curr->next;
    }
    //---------------------------
}

// boolean function
bool DList::empty() const
{
    //Write your code between these lines only
    //---------------------------
    if(head->next==head)
        return true;
    else
        return false;
    //TODO
    //---------------------------
}

// access head element
int DList::headElement() const
{
    if(!empty())
        return head->next->data;
    cerr<<"List is Empty";
}

// access tail element
int DList::tailElement() const
{
    if(!empty())
        return head->prev->data;
    cerr<<"List is Empty";
}

// access element at specific index
int DList::getAt(int idx)
{
    Nodeptr pos = goToIndex(idx);
    if(pos != NULL)
    {
    //Write your code between these lines only
    //---------------------------
     return pos->data;
    //---------------------------
    }
}

// add to the head
void DList::addHead(int newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual First Node
    Nodeptr curr = head->next;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Nodeptr add_head=new Node;
    //---------------------------
    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    add_head->data = newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    add_head->prev = curr->prev;
    curr->prev = add_head;
    (add_head->prev)->next = add_head;
    add_head->next=curr;
    //---------------------------
}

// delete the head
void DList::delHead()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Head Node,
    //Just after DummyHead
    Nodeptr curr = head->next;
    //Update references
    //Write your code between these lines only
    //---------------------------
    head->next=curr->next;
    (curr->next)->prev=curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// add to the head
void DList::addTail(int newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual Last Node
    Nodeptr curr = head;
    //Create New Node
    Nodeptr newnode = new Node;
    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->data=newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    newnode->next=curr->next;
    (curr->next)->prev=newnode;
    newnode->prev=curr;
    curr->next=newnode;
    //---------------------------

}

// delete the head
void DList::delTail()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Tail Node,
    //Just Before DummyHead
    Nodeptr curr = head->prev;
    //Update references
    //Write your code between these lines only
    //---------------------------
    Nodeptr temp = new Node;
    temp=curr;
    (temp->prev)->next=head;
    head->prev=temp->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete temp;
    //---------------------------

}

// add to the head
void DList::addAt(int idx, int newdata)
{
    //Get node at current position
    Nodeptr curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
      Nodeptr New_Node= new Node;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    New_Node->data=newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------

    New_Node->next=(curr->prev)->next;
    New_Node->prev=curr->prev;
    (curr->prev)->next=New_Node;
    curr->prev=New_Node;

    //---------------------------

}

// delete the head
void DList::delAt(int idx)
{
    //Get node at current position
    Nodeptr curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Update references
    //Write your code between these lines only
    //---------------------------
     Nodeptr temp= new Node;
     temp=curr;
     (temp->prev)->next=temp->next;
     (temp->next)->prev=temp->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete temp;
    //---------------------------


}

// utility function to get length of list
int DList::length() const
{
    //Write your code between these lines only
    //---------------------------
     int length=0;
    Nodeptr liveptr;
    liveptr=head->next;
    while(liveptr!=head)
    {
        length++;
        liveptr=liveptr->next;
    }
    return length;
    //---------------------------

}

// display the list
void DList::print() const
{
    //Set the starting point of list
    Nodeptr curr = head->next;
    cout << "[";
    //Iterate and display list.
    //Make sure to handle comma ',' seperation is correct
    if(!empty()){
        cout << curr->data;
        curr = curr->next;
    }
    while(curr != head){
        cout << ", " << curr->data;
        curr = curr -> next;
    }
    cout << "]" << endl;
}

// Add dummy Head and populate
void DList::createDummyHead()
{
    head = new Node;
    head->next = head;
    head->prev = head;
}

// Clear The List
void DList::Clear()
{
    while(!empty())
        delHead();
}

//Go to specific index and return poiter to node at that position
//Indexing is zero based
Nodeptr DList::goToIndex(int idx)
{
    if(idx > length())
    {
        cerr<<"Error! Given index exceed the size of list";
        return NULL;
    }

    //Iterate uptill given index
    Nodeptr curr = head->next;
    //Write your code between these lines only
    //---------------------------
     int index_count=0;
       while(index_count!=idx)
       {
        index_count++;
        curr=curr->next;
       }
    //---------------------------

    return curr;
}

