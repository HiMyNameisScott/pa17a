#include "ForwardList.h"
// ctors

ForwardList::ForwardList(){
    first = nullptr;
    count = 0;
};

ForwardList::ForwardList(const ForwardList& other){};

ForwardList::ForwardList(const std::initializer_list<value_type>& ilist){};

// dtor
// virtual ~ForwardList(){};

// copy assignment
ForwardList& ForwardList::operator=(const ForwardList& rhs){};

/// Clears the contents
void ForwardList::clear(){
    Node * temp;        // This sets a temp node to deallocate mem

    while (first != nullptr){     // runs until we hit the nullptr at end of list
        temp = first;          // temp = head so we don't lose pointer
        first = first->link; // sets next item as head
        delete temp;             // deletes the temp to deallocate memory
    }
    
    count = 0; // Sets count to 0 so we know that we have removed all of the nodaronis
};

/// Inserts a value before pos
ForwardList::iterator insert(ForwardList::iterator pos, const ForwardList::value_type& value){};

/// Erases an element at pos
ForwardList::iterator erase(ForwardList::iterator pos){};


/** NON-MEMBER FUNCTIONS **/

/// Equality comparison operator.
bool operator==(const ForwardList& lhs, const ForwardList& rhs){};

/// Inequality comparison operator.
bool operator!=(const ForwardList& lhs, const ForwardList& rhs){};