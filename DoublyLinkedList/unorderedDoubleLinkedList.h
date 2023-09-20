//Abdallah Elbadan

#ifndef H_UnorderedDoubleLinkedList
#define H_UnorderedDoubleLinkedList

#include "DoubleLinkedList.h"

using namespace std;

template <class Type>
class unorderedDoubleLinkedList : public DoubleLinkedList<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the 

    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: this->first points to the new list, newItem is

    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: this->first points to the new list, newItem 

    void insertNode(const Type& newItem, int index);
    //Function to insert newItem to be the element at location index.

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing 
};


template <class Type>
bool unorderedDoubleLinkedList<Type>::
search(const Type& searchItem) const
{
    dNodeType<Type>* current; //pointer to traverse the list
    bool found = false;

    current = this->first; //set current to point to the this->first 
    //node in the list
    while (current != NULL && !found) { //search the list
        if (current->info == searchItem) { //searchItem is found
            found = true;
        }
        else { // move to the next node until it finds it
            current = current->next;
        }
    }
    return found;
}//end search

template <class Type>
void unorderedDoubleLinkedList<Type>::insertFirst(const Type& newItem)
{

    dNodeType<Type>* newNode = new dNodeType<Type>;

    newNode->info = newItem;

    newNode->next = this->first; //Making the newnode point at the first node

    newNode->prev = NULL;

    if (this->first == NULL) { // Makeing sure that the list not empty
        this->last = newNode;
    }

    else {
        this->first->prev = newNode; //if not empty insert the node before the first node
    }

    this->first = newNode;

    this->count++;

}//end insertFirst

template <class Type>
void unorderedDoubleLinkedList<Type>::insertLast(const Type& newItem)
{

    dNodeType<Type>* newNode = new dNodeType<Type>;
    newNode->info = newItem;
    newNode->next = NULL;

    if (this->first == NULL) { //making sure that the list not empty, 
        newNode->prev = NULL;  //if the list empty, putting the node as the first element
        this->first = newNode;
    }

    if (this->last != NULL) {
        while (this->last->next != NULL) { //finding the last element in the list if the list not empty
            this->last = this->last->next;
        }

        this->last->next = newNode; //making the current last node point at the new node to make it the last one
    }

    newNode->prev = this->last; //making the newnode point at the prevues last node
    this->last = newNode; //changing the last element to the new node

    this->count++;


}//end insertLast

template <class Type>
void unorderedDoubleLinkedList<Type>::insertNode(const Type& newItem, int index)
{
    dNodeType<Type>* temp = this->first;
    dNodeType<Type>* newNode = new dNodeType<Type>;
    newNode->info = newItem;


    if (this->first == NULL) { //add the newItem to the list if there is no list
        newNode->next = NULL;
        newNode->prev = NULL;
        this->first = newNode;
        this->last = newNode;
    }
    else if (index == 0) {  //insert a node in the beggning of the list, 
        newNode->prev = NULL; // Note: I tried to use insertFirst(newItem) to simplify, but for some reason this->count
        newNode->next = this->first; //didn't go up so I hard codded
        this->first->prev = newNode;
        this->first = newNode;

    }
    else if (index < this->count) { //insert node in the middle of the list 
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next; //setting up the pointers for the newNode 
        temp->next = newNode;
        newNode->prev = temp;

        if (newNode->next != NULL) { //change the previous of newNode to next node
            newNode->next->prev = newNode;
        }
    }
    else { // the only one left is inerting the node at the end

        insertLast(newItem);
    }



    this->count++;

}//end insertNode

template <class Type>
void unorderedDoubleLinkedList<Type>::deleteNode(const Type& deleteItem)
{

    dNodeType<Type>* deleteNode = this->first;

    while (deleteNode != nullptr && deleteNode->info != deleteItem) {
        deleteNode = deleteNode->next;
    }

    if (deleteNode == nullptr) {
        cout << "The node you are trying to remove is not in the list\n";
        return;
    }

    else { //if the Node was in the list:



        if (deleteNode == this->first) {
            this->first = deleteNode->next;
            if (this->first != nullptr) {
                this->first->prev = nullptr;
            }
            delete deleteNode;
        }
        else if (deleteNode == this->last) {
            this->last = deleteNode->prev;
            if (this->last != nullptr) {
                this->last->next = nullptr;
            }
            delete deleteNode;
        }
        else {
            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;
            delete deleteNode;
        }
        this->count--;
    }
    //Note: there is an error at the end that I wasn't able to fix, for some reason at the end current from search function will have
    //an error.


}//end deleteNode


#endif
