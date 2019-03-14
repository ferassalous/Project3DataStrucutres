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
    DT* data; // what kind of data you are putting in the list
    LinkedList<DT>* _next;// points to the next node in the list.
    int lengthOfLinkedList;// counter to hold my number of elements in linkedlist.
    LinkedList<DT>* _start; //points to the head node, or the first element in the list.
public:
    LinkedList();
    LinkedList(DT& _data, LinkedList<DT>* _next);
    LinkedList(DT& _data);
    ~LinkedList();
    void insertItem(DT& item); // insert an item
    void removeAt(int index); // removes an element at a specified index.
    int size(); // returns  the size in my list.
    DT& infoAt(int pos);
    void add(DT& x);
    void getNext();
    DT& operator[](int index);
    LinkedList(const LinkedList<DT>&x);
    void insertAt(int index, DT&x);
    void remove();
};
//empty constructor
template<class DT>
LinkedList<DT>::LinkedList()
{
    _next = NULL; // points to the next in the list
    data = NULL;// holds some data value
    _start = NULL; // points to the current node.
    lengthOfLinkedList = 0; //length of my list
}
//This constructor takes in a data type and a linkedlist pointing to the next node.
template <class DT>
LinkedList<DT>::LinkedList(DT& _data, LinkedList<DT>* next)
{
    data = new DT(_data);
    _next = next;
}
// this constructor only takes in a data type
template <class DT>
LinkedList<DT>::LinkedList(DT& _data)
{
    data = new DT(_data);
    _next = NULL;
}
// This is my destructor.
template <class DT>
LinkedList<DT>::~LinkedList<DT>()
{
    if(data != NULL)
    {
        delete data;
        data = NULL;
    }
    if(_next != NULL)
    {
        delete _next;
        _next = NULL;
    }
}
//This is is my add method, which takes in a data type and inserts it into my linked list.
template<class DT>
void LinkedList<DT>::add(DT& x)
{
    //if the data is null create a new data object of that specified type
    if(data == NULL)
    {
        data = new DT(x);
    }
    // else create a temp list and store it into that.
    else
    {
        
        LinkedList<DT>* temp = new LinkedList(*data,_next);
        data = new DT(x);
        _next = temp;
        ++lengthOfLinkedList;
        
    }
    
}
/// this returns info at a specific postion from the linked list. A recursice method.
template<class DT>
DT& LinkedList<DT>::infoAt(int pos)
{
    if(pos == 0)
        return *data;
    else
        return _next -> infoAt(pos-1);
}
/*
 This method returns the size of the linked list: O(1)
 */
template <class DT>
int LinkedList<DT>::size() {
    if(_next == NULL)
    {
        if(data == NULL )return 0;
        else return 1;
    }
    else return (1 + (*_next).size());
}
/*
 This method inserts an item into the list of any DataType. Temp is a temp pointer which will point to start.
 Temp will also 'store' the item given. Temp will then point to start which is Null. _start then will point temp which is the currentNode persay.
 */
template <class DT>
void LinkedList<DT>::insertItem(DT& item) {
    LinkedList<DT>* temp = new LinkedList;
    data  = &item;
    temp -> _next = _start;
    _start  = temp;
    ++lengthOfLinkedList;
    
}
//inserts an item at a specified postion.
template <class DT>
void LinkedList<DT>::insertAt(int index, DT &x)
{
    if(index == 0)
        
    {
        add(x);
    }
    else
    {
        if(_next == NULL)
        {
            _next = new LinkedList<DT>(x);
        }
        
        else
        {
            (*_next).insertAt(index - 1, x);
        }
    }
}
template<class DT>
void LinkedList<DT>::remove()
{
    if(data != NULL)
    {
        delete data;
        LinkedList<DT>* temp = _next;
        data = temp -> data;
        _next = temp -> _next;
        temp -> data = NULL;
        temp -> _next = NULL;
        delete temp;
    }
    
}
//Removes an element at a specified index.
template <class DT>
void LinkedList<DT>::removeAt(int index) {
    if(index == 0)
    {
          remove();
    }
    
    else
    {
        _next -> removeAt(index -1);
    
    }
}
//Overloaded [] operator which returns the element at [ith] element in the linkedlist.
template <class DT>
DT& LinkedList<DT>::operator[](int index)
{
    return infoAt(index);
}
// copy construcor.
template <class DT>
LinkedList<DT>::LinkedList(const LinkedList<DT>&x)
{
    if( x.data == NULL)
    {
        data = NULL;
    }
    else
    {
        data = x.data;
    }
    if(x._next == NULL)
    {
        _next = NULL;
    }
    else{
        _next = x._next;
    }
}
// just a method to get my next element.
template <class DT>
void LinkedList<DT>:: getNext()
{
    return _next;
}
class Term
{
protected:
    int coefficient;
    int exponent;
    // LinkedList<Term>* next = NULL;
public:
    //empty constructor
    Term();
    //construcor that takes in a coefficient and term
    Term(int coefficient,int exponent);
    //SETTERS
    void setCoefficient(int _coefficient);
    void setExponent(int _exponent);
    //GETTERS
    int getCoefficient(); //gets my coefficient
    int getExponent();// gets my term
    void display();
    Term(const Term* in);
};
//emmpty constructor
Term::Term()
{
    coefficient = 0;
    exponent = 0;
}

//Term :: Term(const Term* in)
//{
//    coefficient = in -> coefficient;
//    exponent = in -> exponent;
//}
//construcor that takes in a coefficient and term
Term::Term(int _coefficient,int _exponent)
{
    coefficient= _coefficient;
    exponent = _exponent;
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
int Term::getExponent(){
    return exponent;
}
void Term::display()
{
    cout << getCoefficient() << "X^"  << getExponent();
}
//POLYNOMIAL CLASS
class Polynomail
{
protected:
    LinkedList<Term>* myPoly;//points to my current node.
    //LinkedList<Term>* _next; // points to my next node.
public:
    Polynomail();
    bool insertValues(int coeffcient, int exponent);
    void printPolynomial();
    LinkedList<Term>* getMyPoly();
    int size();
    Polynomail* operator+(Polynomail& x);
    Polynomail* addPolynomail(Polynomail& x);
    Polynomail* multiplyPolynomial(Polynomail& x);
    Polynomail* operator*(Polynomail& x);
    int evaluatePoly(int x);
    int power(int base, int exponent);
    void deleteTerm(int exponent);
    friend ostream& operator<<(ostream&s,const Polynomail* x);
};
//empty constructor
Polynomail::Polynomail()
{
    myPoly = new LinkedList<Term>();
}
/*
 This method takes in a coefficent and an exponent and inserts them into my LinkedList<Polynomial> while also sorting them by degree of exponent.
 */
bool Polynomail::insertValues(int coeffcient, int exponent)
{
    Term *temp = new Term(coeffcient, exponent);
    bool sucess = false;
    // if myPoly is empty insert the term.
    if(myPoly -> size() == 0)
    {
        myPoly -> add(*temp);
        sucess = true;
    }
    else
    {
        bool found = false;
        for(int i = 0; i < myPoly ->size(); i++)
        {
            /*
             checks to see if the exponent entered is less than the exponent of myPoly at the speicifed index, if
             it is add it to the list at that postion.
             */
            
            if((*myPoly).infoAt(i).getExponent() < exponent)
            {
                myPoly -> insertAt(i, *temp);
                found = true;
                sucess = true;
                break;
            }
            /*
             myPoly at the given index equals the exponent given then add the coefficents together and set the coeffcient.
             */
            else if(myPoly -> infoAt(i).getExponent() == exponent )
            {
                int myCoefficent = coeffcient + myPoly->infoAt(i).getCoefficient();
                myPoly -> infoAt(i).setCoefficient(myCoefficent);
                found = true;
                sucess = true;
                break;
            }
            // if neither condtion is met, insert at the end of the list.
            if(!found)
            {
                myPoly -> insertAt(myPoly-> size(), *temp);
                sucess = true;
                found = true;
                break;
            }
        }
    }
    return sucess;
}
// this method removes an elemennt specified an exponet and sets the coeffcient = to zero.
void Polynomail::deleteTerm(int exponent)
{
    for(int i = 0; i < myPoly -> size(); ++i)
    {
        if(myPoly->infoAt(i).getExponent() == exponent)
        {
            myPoly -> removeAt(i);
        }
        
    }
      cout << "There is No Term in this Polynomial with Exponent " << exponent << " To Be Removed."<<endl;
}
void Polynomail::printPolynomial()
{
    for(int i = 0; i < myPoly-> size(); ++i)
    {
        // cout<< "Reached Display Method" << endl;
        cout << "(" << myPoly -> infoAt(i).getCoefficient() << "," << myPoly ->infoAt(i).getExponent()<<")";
        if(i != myPoly -> size()-1)
        {
            cout << "+";
        }
    }
    cout << endl;
    
}
//Overloaded ostream operator
ostream& operator << (ostream&s, const Polynomail* x)
{
    for(int i = 0; i < x->myPoly-> size(); ++i)
    {
        // s << "Reached Display Method" << endl;
        s << "(" << x->myPoly -> infoAt(i).getCoefficient() << "," << x->myPoly ->infoAt(i).getExponent()<<")";
        if(i != x->myPoly -> size()-1)
        {
            s << "+";
        }
    }
    s << endl;
    return s;
}
// Polynomial Addition method.
Polynomail* Polynomail:: addPolynomail(Polynomail& x)
{
    Polynomail* temp = new Polynomail();
    // this loops through myPoly and gets the coefficents and exponents and inserts them into a polynomial.
    for(int i = 0; i < myPoly ->size(); ++i)
    {
        //getting the coeffeicient
        int coeffcientOfMyPoly = myPoly -> infoAt(i).getCoefficient();
        //getting the exponent
        int exponentOfMyPoly = myPoly -> infoAt(i).getExponent();
        temp -> insertValues(coeffcientOfMyPoly, exponentOfMyPoly);
    }
    // this loops through the given poly in the parameter and gets the coefficents and exponents and inserts them into a polynomial.
    for(int j = 0; j < x.myPoly -> size(); ++j)
    {
        int coefficentOfMyPolyToAdd = x.myPoly->infoAt(j).getCoefficient();
        int exponentOfMyPolyToAdd = x.myPoly->infoAt(j).getExponent();
        temp -> insertValues(coefficentOfMyPolyToAdd, exponentOfMyPolyToAdd);
    }
    
    
    return temp;
}
//Overloaded Addition opeprator
Polynomail* Polynomail:: operator+(Polynomail &x)
{
    Polynomail* temp = new Polynomail();
    for(int i = 0; i < myPoly ->size(); ++i)
    {
        int coeffcientOfMyPoly = myPoly -> infoAt(i).getCoefficient();
        int exponentOfMyPoly = myPoly -> infoAt(i).getExponent();
        temp -> insertValues(coeffcientOfMyPoly, exponentOfMyPoly);
    }
    for(int j = 0; j < x.myPoly -> size(); ++j)
    {
        int coefficentOfMyPolyToAdd = x.myPoly->infoAt(j).getCoefficient();
        int exponentOfMyPolyToAdd = x.myPoly->infoAt(j).getExponent();
        temp -> insertValues(coefficentOfMyPolyToAdd, exponentOfMyPolyToAdd);
    }
    
    
    return temp;
}
//Evaluates the polynomial with a given X value.
int Polynomail::evaluatePoly(int x)
{
    int result = 0; // the result following evaluation
    for(int i =0; i < myPoly ->size(); i++)
    {
        int coeffecient = myPoly->infoAt(i).getCoefficient(); // get the coefficent.
        result += (coeffecient * power(x,myPoly->infoAt(i).getExponent())); // multiply the coefficent * base to the power of the exponent.
    }
    return result;
}
// A function to provide me the abilty to do power functions
int Polynomail::power(int base, int exponent)
{
    // if the exponent is 0, retrun 1
    if (exponent == 0)
    {
        return 1;
    }
    else
    {
        return base * power(base, exponent - 1);
    }
}
//Multiplication method
Polynomail* Polynomail:: multiplyPolynomial(Polynomail &x)
{
    Polynomail* temp = new Polynomail();
    for(int i=0; i < myPoly -> size(); ++i)
    {
        for(int j =0; j < x.myPoly-> size(); ++j)
        {
            // get the coefficents and myltiply them together.
            int coeffcient = myPoly-> infoAt(i).getCoefficient() * x.myPoly -> infoAt(j).getCoefficient();
            //get the exponents and add them togeehter.
            int exponent = myPoly -> infoAt(i).getExponent() + x.myPoly -> infoAt(j).getExponent();
            temp -> insertValues(coeffcient, exponent);
            
        }
    }
    return temp;
}
//Multiplication Operator
Polynomail* Polynomail:: operator*(Polynomail &x)
{
    Polynomail* temp = new Polynomail();
    for(int i=0; i < myPoly -> size(); ++i)
    {
        for(int j =0; j < x.myPoly-> size(); ++j)
        {
            int coeffcient = myPoly-> infoAt(i).getCoefficient() * x.myPoly -> infoAt(j).getCoefficient();
            int exponent = myPoly -> infoAt(i).getExponent() + x.myPoly -> infoAt(j).getExponent();
            temp -> insertValues(coeffcient, exponent);
            
        }
    }
    return temp;
    
}
// gets the polynomial, not used but thought i wouldve needed it.
LinkedList<Term>* Polynomail:: getMyPoly()
{
    return myPoly;
}
int main() {
    Polynomail*  Polynomials = new Polynomail[10];
    char command;
    int polynum,coefficient,exponent,value;
    int i,j;
    cin >> command;
    while (!cin.eof()) {
        switch(command)
        {
            case 'I': cin >> polynum >> coefficient >> exponent;
                Polynomials[polynum].insertValues(coefficient, exponent);
                break;
            case 'D': cin >> polynum >> exponent;
                Polynomials[polynum].deleteTerm(exponent);break;
            case 'A': cin >> i >> j; cout << "The Result Of Additon is:"; cout << Polynomials[i] + Polynomials[j];  break;
            case 'P': cin >> polynum; cout <<"Polynomial " << polynum<<": "; cout << &Polynomials[polynum]; break;
            case 'M': cin >> i >> j; cout << "The Result Of Multiplication is:"; cout << Polynomials[i] * Polynomials[j]; break;
            case 'E': cin >> polynum >> value; cout << "The result of Polynomial:" << polynum<<" Evaluated at X=" << value << ": ";
                cout << Polynomials[polynum].evaluatePoly(value) << endl; break;
            default: cout << "I missed Something."<<endl;
        }
        cin >> command;
    }
    return 0;
    
}
