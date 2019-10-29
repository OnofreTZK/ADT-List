#ifndef LIST_H
#define LIST_H

#include <iostream>

namespace sc{ // sequence container.

template< typename T >

class list
{
    private:
        struct Node{
            T data; //> value
            Node * next; //> pointer to next node.
            Node * prev; //> pointer to prev node.
        };

        Node * head; //> pointer to first/top node.


    public:
/*-------------------------- Constructors --------------------------------*/
        
}


}
