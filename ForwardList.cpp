#include "ForwardList.h"
// ctors

ForwardList::ForwardList()
{
    first = nullptr;
    count = 0;
};


ForwardList::ForwardList(const ForwardList &other)
{
    Node *newNode{}; // pointer to create a node
    Node *current{}; // creates a copy of current node

    if (first != nullptr) // if the list we want to copy to is not empty, make empty
    {
        clear();
    }

    if (other.first == nullptr) // otherList is empty if first == nullptr
    {
        first = nullptr;
        count = 0;
    }
    else
    {
        current = other.first;      // sets current to the head of the other list
        count = other.count;        // sets count to other.count

        first = new Node;         // create a node
        first->info = current->info; // sets the first info to current info
        first->link = nullptr;       // sets the new head to pointer
    }

    while (current != nullptr)      // since current is now using rhs we traverse rhs
    {
        newNode = new Node{};       // creates a new node
        newNode->info = current->info;  // assigns the info to new-info
        newNode->link = current->link;        // lets new

        current = current->link;
    }
};

ForwardList::ForwardList(const std::initializer_list<value_type> &ilist){
    for (const auto& i : ilist){
        insert(begin(), i); 
    }
};

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
        newNode->link = current->link;        // lets new

        current = current->link;
    }

    return *this;
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
    Node *current{};            // stores current pointer value
    Node *trailCurrent{};       // stores previous trialing node

    Node *newNode{};            // creates a new node

    bool found;

    newNode = new Node;       // allocates to newNode
    newNode->info = value;      // sets info to the param value
    newNode->link = nullptr;    // sets link to nullptr.

    if (first == nullptr)
    {
        first = newNode; // newNode = first as the rest of the list is empty
        count ++;   // adds this new node to the count
    }
    else
    {
        current = first;       // assigns n to p: n{p->info, p->link}
        found = false; // assigns the p->link to the address of the next node

        while (current != nullptr && !found) // checks for nullptr

            // This block is used solely to traverse through the link list

            if (current->info == value){ // checks to see if we found value
                found = true;            // terminates while loop
            } else {                        
                trailCurrent = current;  // moves the trail to the next
                current = current->link; // updates current to next item in list
            }
             

        if(current == first){         // We are at the start of the list
            newNode->link = first;
            first = newNode;
            count++;
        } else {
            trailCurrent->link = newNode; // We are not at the start of the list
            newNode->link = current;
            count++;
        }
    }
    return current;
};

/// Erases an element at pos
ForwardList::iterator ForwardList::erase(ForwardList::iterator pos){
    Node *current{};        // used to traverse list
    Node *trailCurrent{};   // used to keep track of previous node

    bool found;

    if (first == nullptr){
        //We can throw an exception here
    } else {
        current = first;
        found = false;

        while (current != nullptr && !found){
            if (current->info >= *pos){
                found = true;
            } else {
                trailCurrent = current;
                current = current->link;
            }

        if (current == nullptr){
            // No item to be deleted, we can throw an exception
        } else {
            if (current->info == *pos){
                if (first == current){
                    first = first->link;
                    
                    delete current;
                } else {
                    trailCurrent->link = current->link;

                    delete current;
                }
                count--;
            } else {
                // item to be deleted does not exist
            }
        }
        }
    }
    return pos;
};

/** NON-MEMBER FUNCTIONS **/

/// Equality comparison operator.
bool operator==(const ForwardList &lhs, const ForwardList &rhs){
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};

/// Inequality comparison operator.
bool operator!=(const ForwardList &lhs, const ForwardList &rhs){
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};

std::ostream& operator<<(std::ostream& output, const ForwardList& list) {
    //using namespace std;
    const int CW{ 14 };  // column width

    output << "┌────────────────┬────────────────┬────────────────┐\n"
              "│ node address   │           info │           link │\n"
              "├────────────────┼────────────────┼────────────────┤\n";

    for (auto it = list.begin(); it != list.end(); ++it) {
        output << "│ "  << std::left << std::setw(CW) << it.operator->() << std::right
               << " │ " << std::setw(CW) << it->info
               << " │ " << std::setw(CW) << it->link << " │\n";
    }

    output << "└────────────────┴────────────────┴────────────────┘\n";
    output << "size() == " << list.size() << '\n';

    return output;
}