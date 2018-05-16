#include "Pizza.h"
#include <iostream>
#include <string>
using namespace std;

Pizza::Pizza()
{

}

void Pizza::set_pizza_size(char pizza_size)
{
    switch (tolower(pizza_size))
    {
        case 's':
            this-> pizza_size = pizza_size;
            break;
        case 'm':
            this-> pizza_size = pizza_size;
            break;
        case 'l':
            this-> pizza_size = pizza_size;
            break;
        default:
            this-> pizza_size = '\0';
    }
}
bool Pizza::add_topping(string new_topping) 
{
    if(topping_count < Max_toppings)
    {
        toppings[topping_count++] =  new_topping;
        return true;
    } else 
    {
        return false;
    }
}

void Pizza::set_toppings(string toppings[])
{
    for(topping_count; topping_count < Max_toppings; topping_count++)
    {
       add_topping(*toppings++);
    }
}

char Pizza::get_pizza_size() const
{
    return pizza_size;
}

string* Pizza::get_toppings() 
{
    return toppings;
}
