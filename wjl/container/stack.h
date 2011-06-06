#ifndef _STACK_H_
#define _STACK_H_

template<class T>
class Node
{
public:
    /*Node(T invalue): m_Value(invalue), m_Next(0) {}*/
    Node(T invalue);
    ~Node();

    T getValue() const;
    void setValue (T value);
    Node<T>* getNext() const;
    void setNext(Node<T>* next);

private:
    T m_Value;
    Node<T>* m_Next;
};

template<class T>
class Stack 
{
public:
    Stack ();
    ~Stack ();
    void push(const T& t);
    T pop();
    T top() const;
    int count() const;

private:
    Node<T> *m_Head;
    int m_Count;
};

#endif
