//
//  main.cpp
//  Project3DataStructures
//
//  Created by Feras Salous  on 2/27/19.
//  Copyright © 2019 Feras Salous . All rights reserved.
//

#include <iostream>
using namespace std;
template <class DT>
class LinkedList {
    protected:
        DT data; // what kind of data you are putting in the list
        LinkedList<DT>* _next;// points to the next node in the list.
        int lengthOfLinkedList;// counter to hold my number of elements in linkedlist.
        LinkedList<DT>* _start; //points to the head node, or the first element in the list.
    public:
        LinkedList();
        void insertItem(DT item); // insert an item
        void remove(DT i); // removes a specified element
        void displayElements(); //displays the elements in the linked list
        int size(); // returns  the size in my list.
        DT infoAt(int i);
};
//empty constructor
template<class DT>
LinkedList<DT>::LinkedList()
{
    _next = NULL; // points to the next in the list
    data = 0;// holds some data value
    _start = NULL; // points to the current node.
    lengthOfLinkedList = 0; //length of my list
}
/*
 This method returns the size of the linked list: O(1)
 */
template <class DT>
int LinkedList<DT>::size() {
    return  lengthOfLinkedList;
}
/*
This method inserts an item into the list of any DataType. Temp is a temp pointer which will point to start.
Temp will also 'store' the item given. Temp will then point to start which is Null. _start then will point temp which is the currentNode persay.
 */
template <class DT>
void LinkedList<DT>::insertItem(DT item) {
    LinkedList<DT>* temp = new LinkedList;
    temp -> data = item;
    temp -> _next = _start;
    _start  = temp;
    ++lengthOfLinkedList;
}
/*
    This method searches for a specified data value and removes it from the list.
 */
template <class DT>
void LinkedList<DT>::remove(DT i) {
    if( _start != NULL)
    {
        LinkedList<DT>* temp = _start;
        if(i == temp -> data)
        {
            _start = _start -> _next;
            delete temp;
            lengthOfLinkedList--;
        }
        else
        {
            while( temp -> _next != NULL && i != temp-> _next -> data)
            {
                temp = temp -> _next;
            }
            LinkedList<DT>* myValue = temp -> _next;
            if(myValue !=NULL)
            {
                temp -> _next = myValue -> _next;
                delete myValue;
                lengthOfLinkedList--;
            }
        }
    }
}
/*
 This method returns the data at a specified index in the list.
 */
template <class DT>
DT LinkedList<DT>::infoAt(int index) {
    LinkedList<DT>* temp = _start;
    int count = 0;
    //checks to see if count does not equal the index if it does not, jump to the next node and increment count till the index and count are equal.
    while (count != index) {
        temp = temp -> _next; //jumping to next node
        count++; //incrementing count
    }
    // if the list is empty return null.
    if( temp == NULL)
    {
        return 0;
    }
    // return the data at the node temp is pointing at.
    return temp -> data;

}
/*
    This Method displays my elements in the list.
 */
template<class DT>
void LinkedList<DT>::displayElements()
{
     LinkedList<DT>* temp = _start;
    //checks to see first if temp is not null
    while(temp != NULL)
    {
    //prints out data at current node
    cout << temp -> data << endl;
    //jumps to the next node.
    temp  = temp -> _next;
    }
   
}
//TERM CLASS
class Term
{
protected:
    int coefficient;
    int exponent;
    LinkedList<Term>* next = NULL;
public:
    //empty constructor
    Term();
    //construcor that takes in a coefficient and term
    Term(int _coefficient,int _exponent,LinkedList<Term>* _next);
    //SETTERS
    void setCoefficient(int _coefficient);
    void setExponent(int _exponent);
    //GETTERS
    int getCoefficient(); //gets my coefficient
    int getTerm(); // gets my term
};
//emmpty constructor
Term::Term()
{
    coefficient = 0;
    exponent = 0;
}
 //construcor that takes in a coefficient and term
Term::Term(int _coefficient,int _exponent,LinkedList<Term>* _next)
{
    coefficient = _coefficient;
    exponent = _exponent;
    next = _next;
}
void Term::setExponent(int _exponent)
{
    exponent = _exponent;
}
void Term::setCoefficient(int _coefficient)
{
    coefficient = _coefficient;
}
int Term::getCoefficient(){
    return coefficient;
}
int Term::getTerm(){
    return exponent;
}
//POLYNOMIAL CLASS
class Polynomail
{
    protected:
    LinkedList<Term>* myPoly; //points to my current node.
    public:
    Polynomail();
    void insertValues(int coeffcient, int exponent);
    void display();
};
Polynomail::Polynomail()
{
    myPoly = NULL;
}
void Polynomail::insertValues(int coeffcient, int exponent)
{
    Term* temp = new Term;
    temp -> setCoefficient(coeffcient);
    temp -> setExponent(exponent);
    myPoly -> insertItem((*temp));
}
void Polynomail::display()
{
    cout << myPoly;
}
int main() {
   
    LinkedList<int>* x = new LinkedList<int>();
   //cout<<  x -> size();
    x -> insertItem(1); //insert function
    x -> insertItem(2); //insert function
    x -> insertItem(3); //insert function
    cout << "These are my elements:" <<  endl;
    x -> displayElements(); //diplays elements
    cout << "This is the size:";
    cout << x -> size(); // retruns the size.
    cout << endl;
    cout << "This is info at 0 Before Deletion:"<<endl;
    cout << x -> infoAt(0);
    cout <<endl;
    x -> remove(3); //removes 3
    cout << "Elements after Deletion:"<<endl;
    x->displayElements();
    cout << "This is the element at 1 after Deltetion: \n"<<endl;
    cout << x-> infoAt(1);
    cout <<endl;
    //Test on char.
    LinkedList<char>*  char_x = new LinkedList<char>();
    char_x -> insertItem('a');
    cout << "My Char Element:"<<endl;
    char_x -> displayElements();
    
    Polynomail* _x = new Polynomail;
    _x -> insertValues(2, 3);
    _x -> display();
    
    
    
    
    return 0;
}
