#include <iostream>
#include "Linked_List.h"
//#include "./include/Linked_List.h"
#include "Order.h"
#include<cstdlib>

int main()
{

   Linked_List order_list;
   Order myOrder;
   string decision, exit;
   do
   {
       cout << "Would you like to create an order or see the existing orders? (Enter c if you want to make an order or s if you want to see the orders.)";
       getline(cin, decision);

       if(decision == "c")
       {
           order_list.create_order();
       }
       else
       {
           order_list.delivery_check();
           order_list.print_list();
       }

       cout << "Do you want to continue? (Enter either Yes or No)";
       cin >> exit;
       cin.ignore();


   }while(exit == "yes");
   return EXIT_SUCCESS; 
   //return 0;

}
