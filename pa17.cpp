#include "ForwardList.h"
#include "ForwardList.cpp"

ForwardList& unique(ForwardList& List);
int main()
{
    ForwardList test3 {10, 20, 30 ,40, 50};
    
    unique(test3);
    
return 0;
}

ForwardList& unique(ForwardList& list){

    std::cout << list << std::endl;
    return list;
}