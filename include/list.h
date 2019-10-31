#ifndef LIST_H
#define LIST_H

#include <iostream> // cin/cout
#include <iterator> // std::distance
#include <initializer_list> // std::initializer_list
#include <cstdlib> // size_t
#include <algorithm>

/* ALIAS */
using size_type = size_t;
using value_type = int;

namespace sc{ // sequence container.

    template< typename T >

        class list
        {
            private:
                struct Node{
                    T data; //> value
                    Node * next =nullptr; //> pointer to next node.
                    Node * prev =nullptr; //> pointer to prev node.
                };

                Node * head; //> pointer to first/top node.
                Node * tail; //> pointer to last/bottom node.
                size_type m_size;


            public:
/*=====================================================================================*/
//              Iterator
/*=====================================================================================*/

                class iterator
                {
                    private:

                        Node * current;

                    public:



                };

/*=====================================================================================*/
//              Const Iterator
/*=====================================================================================*/

                class const_iterator
                {
                    private:

                        const Node * current;

                    public:


                };
/*=====================================================================================*/
//               Getting an iterator

                iterator begin()
                {
                    return iterator(this->head);
                }

                const_iterator cbegin() const
                {
                    return const_iterator(this->head);
                }

                iterator end()
                {
                    return iterator(this->tail);
                }

                const_iterator cend() const
                {
                    return const_iterator(this->tail);
                }
/*=====================================================================================*/


/*-------------------------- Constructors & Destructor --------------------------------*/
                // Default constructor.
                list()
                {
                    /* empty list */
                    head = tail;
                    tail = head;

                    m_size = 0;
                }

                // Constructor with `count` times T().
                explicit list( size_type count )
                {
                    size_type aux = 0; // count.

                    // linking list
                    head = tail;
                    tail = head;


                    while( aux < count )
                    {
                        push_front( T() );
                        aux++;
                    }

                    m_size = count;
                }

                // Constructor with the contents in range( first, last ).
                template< typename InputIt >
                  list( InputIt first, InputIt last )
                  {
                      // linking list
                      head = tail;
                      tail = head;

                      while( first != last )
                      {
                          push_front(*first);
                          first++;
                      }

                      m_size = std::distance( first, last );
                  }

                // Constructs the list with the deep copy of contents of other.
                list( const list& other )
                {
                      // linking list
                      head = tail;
                      tail = head;

                      Node * runner = other.head;

                      while( runner->next )
                      {
                          push_front( runner->data );
                          runner = runner->next;
                      }

                      m_size = other.size();
                }

                // Constructor with initializer list
                list( std::initializer_list<T> ilist )
                {
                      // linking list
                      head = tail;
                      tail = head;

                      size_type it = 0;

                      while( it < ilist.size() )
                      {
                          push_front( *( ilist.begin() + it ) );
                          it++;
                      }

                      m_size = ilist.size();
                }

                // Destructor;
                ~list();

                // Operator = overloading ===============================================
                // Replace the contents with a copy of the contents of other.
                list& operator=( const list& other )
                {
                      // linking list
                      head = tail;
                      tail = head;

                      Node * runner = other.head;

                      while( runner->next )
                      {
                          push_front( runner->data );
                          runner = runner->next;
                      }

                      m_size = other.size();

                      return *this;
                }

                // Repalce the contents with those identified by a initializer list.
                list& operator=( std::initializer_list<T> ilist )
                {
                      // linking list
                      head = tail;
                      tail = head;

                      size_type it = 0;

                      while( it < ilist.size() )
                      {
                          push_front( *( ilist.begin() + it ) );
                          it++;
                      }

                      m_size = ilist.size();

                      return *this;
                }
/*-------------------------------------------------------------------------------------*/


/*------------------------ Commom operations to all list ------------------------------*/
                // Return the number of elements in the container.
                size_type size()const{ return m_size; }

                // Remove(either logically or physically) all elements from the container.
                void clear()
                {
                    while( !empty() )
                    {
                        pop_front();
                    }

                    m_size = 0;
                }

                // Return true if the container contains no elements, and false otherwise.
                bool empty(){ return head == nullptr; }

                // Adds value to the front of the list.
                void push_front( const T & value )
                {
                    // Create node.
                    Node * temp = new Node;

                    // Put value and link to list.
                    temp->data = value;
                    temp->next = head;
                    temp->prev = head->prev;

                    // link head.
                    head = temp;

                    m_size++;
                }

                // Adds value to the end of the list.
                void push_back( const T & value )
                {
                    // Create node.
                    Node * temp = new Node;

                    // Put value and link to list.
                    temp->data = value;
                    temp->next = tail;
                    temp->prev = tail->prev;

                    // link tail.
                    tail = temp;

                    m_size++;
                }

                // Removes the object at the end of the list.
                void pop_back( void )
                {
                    if( empty() ){ return; } //empty condition.

                    Node * temp = tail;

                    tail = tail->prev;

                    delete[] temp;

                    m_size--;
                }

                // Removes the object at the front of the list.
                void pop_front( void )
                {
                    if( empty() ){ return; } //empty condition.

                    Node * temp = head;

                    head = head->next;

                    delete[] temp;

                    m_size--;
                }

                // Returns the object at the end of the list.
                const T & back( void )
                {
                    return tail->data;
                }

                // Returns the object at the beginning of the list.
                const T & front( void )
                {
                    return head->data;
                }

                // Replaces the content of the list with copies of value.
                void assign( const T & value )
                {
                    Node * runner = head;

                    while( runner->next )
                    {
                        runner->data = value;
                        runner = runner->next;
                    }
                }


        };
/*-------------------------------------------------------------------------------------*/

} // END namespace sc

/*---------------------------- Non-member functions -----------------------------------*/

template< typename T >

bool operator==( const sc::list<T> & lhs, const sc::list<T> & rhs )
{
    if( lhs.size() == rhs.size() )
    {
        auto l = lhs.cbegin();
        auto lLast = lhs.cend();
        auto r = rhs.cbegin();
        while( l != lLast )
        {
            if( *l++ != *r++ )
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }

    return false;
}

template< typename T >

bool operator!=( const sc::list<T> & lhs, const sc::list<T> & rhs )
{
    if( lhs.size() == rhs.size() )
    {
        auto l = lhs.cbegin();
        auto lLast = lhs.cend();
        auto r = rhs.cbegin();
        while( l != lLast )
        {
            if( *l++ != *r++ )
            {
                return true;
            }
        }

        return false;
    }
    else
        return true;
}
#endif
