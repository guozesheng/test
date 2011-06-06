#include <iostream>
#include "stack.h"
using namespace std;

// class Node
//template<class T> 
//Node<T> :: Node(T invalue): m_Value(invalue), m_Next(0)
//{}

template<class T> 
Node<T> :: Node(T invalue)
{
    m_Value = invalue;
    m_Next = 0;
}

template<class T> 
Node<T> :: ~Node()
{
    cout<<m_Value<<" deleted "<<endl;
    if (m_Next) 
    {
        delete m_Next;
    }
}

template<class T> 
T Node<T> :: getValue() const
{
    return m_Value;
}

template<class T> 
void Node<T> :: setValue (T value)
{
    m_Value = value;
}

template<class T> 
Node<T>* Node<T> :: getNext() const
{
    return m_Next;
}

template<class T> 
void Node<T> :: setNext(Node<T>* next)
{
    m_Next = next;
}

// class Stack
template<class T>
Stack<T> :: Stack()
{
    m_Head = 0;
    m_Count = 0;
}

template<class T>
Stack<T> :: ~Stack()
{
    delete m_Head;
}

template<class T>
void Stack<T> :: push (const T& value)
{
    Node<T> *newNode = new Node<T>()
}
