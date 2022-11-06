#include "ForwardList.h"
// ctors

ForwardList::ForwardList()
{
    first = nullptr;
    count = 0;
};


ForwardList::ForwardList(const ForwardList &other)
{
    first = nullptr;
    *this = other;
};

ForwardList::ForwardList(const std::initializer_list<value_type> &ilist){};

// dtor
ForwardList::~ForwardList(){ clear(); };

// copy assignment
ForwardList &ForwardList::operator=(const ForwardList &rhs)
{
    Node *newNode{}; // pointer to create a node
    Node *current{}; // creates a copy of current node

    if (first != nullptr) // if the list we want to copy to is not empty, make empty
    {
        clear();
    }

    if (rhs.first == nullptr) // otherList is empty if first == nullptr
    {
        first = nullptr;
        count = 0;
    }
    else
    {
        current = rhs.first;      // sets current to the head of the other list
        count = rhs.count;        // sets count to other.count

        first = new Node;         // create a node
        first->info = current->info; // sets the first info to current info
        first->link = nullptr;       // sets the new head to pointer
    }

    while (current != nullptr)      // since current is now using rhs we traverse rhs
    {
        newNode = new Node{};       // creates a new node
        newNode->info = current->info;  // assigns the info to new-info
        newNode->link = nullptr;        // lets new

        current = current->link;
    }
};

/// Clears the contents
void ForwardList::clear()
{
    Node *temp; // This sets a temp node to deallocate mem

    while (first != nullptr)
    {                        // runs until we hit the nullptr at end of list
        temp = first;        // temp = head so we don't lose pointer
        first = first->link; // sets next item as head
        delete temp;         // deletes the temp to deallocate memory
    }

    count = 0; // Sets count to 0 so we know that we have removed all of the nodaronis
};

/// Inserts a value before pos
ForwardList::iterator ForwardList::insert(ForwardList::iterator pos, const ForwardList::value_type &value)
{
    Node *newNode{}; // pointer to create the new node
    Node *p{};       // stores previous pointer value
    Node *q{};       // stores current

    if (empty() || pos == begin())
    {
        newNode = new Node{value, nullptr}; // creates the new node.
        first = newNode;
    }
    else
    {
        p = first;       // assigns n to p: n{p->info, p->link}
        q = first->link; // assigns the p->link to the address of the next node

        while (q != nullptr && q != pos)
        {
            p = q;       // assigns n to p: n{p->info, p->link}
            q = q->link; // assigns the p->link to the address of the next node
        }

        newNode = new Node {value, p->link};
        p->link = newNode;
    }

    count++;
};

/// Erases an element at pos
ForwardList::iterator erase(ForwardList::iterator pos){
    // while current != pos traverse
    // if curent = pos
    // set p to current->link
    //
};

/** NON-MEMBER FUNCTIONS **/

/// Equality comparison operator.
bool operator==(const ForwardList &lhs, const ForwardList &rhs){};

/// Inequality comparison operator.
bool operator!=(const ForwardList &lhs, const ForwardList &rhs){};