#ifndef PIZZA_H
#define PIZZA_H

#include <cstdlib>
#include <string>
using namespace std;

class Pizza
{
  public:
    typedef size_t size_type;
    static const size_type Max_toppings = 5;

    Pizza();
    void set_pizza_size(char pizza_size);
    void set_toppings(string toppings[]);
    char get_pizza_size() const;
    string *get_toppings();
    bool add_topping(string new_topping);
    void print_Pizza() const;

  private:
    char pizza_size;
    size_type topping_count = 0;
    string toppings[Max_toppings];
    void print_toppings() const;
};

#endif // PIZZA_H
