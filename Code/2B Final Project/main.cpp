#include <iostream>
//#include "Linked_List.h"
//#include "./include/Linked_List.h"
#include "Order.h"
#include<cstdlib>

int main()
{

   Order o1, o2;


   o1.take_order();
    cout << "\norder1\n\n";
    cout << "cook time " << o1.get_cookTime() << endl;
    cout << "order time " << o1.get_order_time() << endl << endl;
   o1.print_order();

   o2 = o1;
    cout << "\norder2\n\n";
    cout << "cook time " << o2.get_cookTime() << endl;
    cout << "order time " << o2.get_order_time() << endl << endl;
   o2.print_order();
   
    return EXIT_SUCCESS; 

}
