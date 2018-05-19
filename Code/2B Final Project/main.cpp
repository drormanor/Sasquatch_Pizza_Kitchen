#include <iostream>
#include "Linked_List.h"
//#include "./include/Linked_List.h"
//#include "Order.h"
#include <cstdlib>

int main()
{

    Linked_List order_list;
    Order myOrder;
    char decision;
    cout << "\n\nWelcome to the Sasquatch Pizza Kitchen order manager\n\n";

    do
    {
        cout << "\nOption Menu:\n\n";
        cout << "To create an order enter C\n";
        cout << "To display exisiting orders enter S\n";
        cout << "TO exit the order manager enter X\n";

        cin >> decision;
        cin.ignore();
        decision = tolower(decision);

        if (decision == 'c')
        {
            order_list.create_order();
        }
        else if (decision == 's')
        {
            order_list.delivery_check();
            order_list.print_list();
        }

    } while (decision != 'x');
    return EXIT_SUCCESS;
    //return 0;
}
