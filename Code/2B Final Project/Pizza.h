#ifndef PIZZA_H
#define PIZZA_H

#include <cstdlib>
#include <string>
using namespace std;

class Pizza
{
public:
  // TYPEDEF
  typedef size_t size_type;

  // CONSTRUCTOR
  Pizza();
  // Member functions
  void set_pizza_size(char pizza_size);
  // Summary: will set the pizza size
  // Preconditions: a Pizza object was instantiated
  // *********************************************************************
  
  void Pizza::set_toppings(string toppings[]);
    // Summary: will copy the argument into the the object array
    // Preconditions: a Pizza object was instantiated
    // ********************************************************************

  bool add_topping(string new_topping);
    // Summary: will add toping to the toppings  array
    // Preconditions: a Pizza object was instantiated
    // Postconditions: an array with not more than 5 toppings
    // ********************************************************************

  string *get_toppings();
    // Summary: will return a pointer to the toppings array
    // Preconditions: a Pizza object was instantiated
    // ********************************************************************
  
  bool remove_last_topping();
    // Summary: will remove the last topping added
    // Preconditions: a Pizza object was instantiated and the toppings 
    // array is not empty
    // Postconditions: a topping. count is decreased by 1 and a bool 
    // is returned
    // ********************************************************************

  void print_Pizza();
    // Summary: will print a summary of the pizza object
    // Preconditions: a Pizza object was instantiated
    // ********************************************************************

  // Constant member function
  char get_pizza_size() const;
    // Summary: return pizza size
    // Preconditions: a Pizza object was instantiated
    // Postconditions: pizza_size was returned
    // ********************************************************************

private:
  static const size_type Max_toppings = 5;
  char pizza_size;
  size_type topping_count = 0;
  string toppings[Max_toppings];

  void print_toppings() const;
    // Summary: will print the toppings array
    // Preconditions: a Pizza object was instantiated and the toppings 
    // array is not empty
    // Postconditions: all the elements in the array will print out with
    // a comma separator and before the last element will add "and" 
    // ********************************************************************
};

#endif // PIZZA_H
