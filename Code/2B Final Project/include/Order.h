#include "Node.h"
#include "Pizza.h"
#include <cstdlib>
#include <time.h>
#include <string>
#include <unordered_map>

using namespace std;
class Order
{
public:
  typedef Node<Pizza>::value_type data_type;
  typedef size_t size_type;
  static const size_type Deliverry_time = 30;
  static const size_type Max_toppings = 5;
  static const size_type Topping_list_size = 20;
  
  // Constructor creates an empty list
  // ******************************************************************************************
  Order();
  // Summary: Constructor creates a linked list object with count set at 0.
  // ******************************************************************************************


  void set_phone(string phone);
  // Summary:  setter for the customer phone
  // ******************************************************************************************

  void set_name(string name);
  // Summary:  setter for the customer name
  // ******************************************************************************************
  void set_cookTime(int cookTime);
  // Summary:  setter for the order cook time
  // ******************************************************************************************

  string get_phone(string phone) const;
  // Summary:  getter for the customer phone
  // ******************************************************************************************

  string get_name(string name) const;
  // Summary:  getter for the customer name
  // ******************************************************************************************

  int get_cookTime() const;
  // Summary:  getter for the order cook time
  // ******************************************************************************************
  time_t get_start_time() const { return order_time; };
  // Summary: a timestamp will be returned
  // *********************************************************************

  Node<Pizza> *getHeadPtr();
  // Summary: Returns a pointer to the head Node of the list.
  // Preconditions: The list has been initialized.
  // Postconditions: A pointer to the head has been returned.
  // ******************************************************************************************
  // ******************************************************************************************
  const Node<Pizza> *getHeadPtr() const;
  // Summary: Returns a pointer to the head Node of the list.
  // Preconditions: The list has been initialized.
  // Postconditions: A pointer to the head has been returned.
  // ******************************************************************************************


  size_type list_length() const;
  // Summary: This function returns the number of Nodes in the list.
  // Preconditions:  A list exists
  // Postconditions: Returns 0 if list is empty, otherwise it returns the number of items  in the list, i.e. count
  // ******************************************************************************************
  // ******************************************************************************************
  bool isEmpty() const;
  // Summary: This function returns true if the list is empty.
  // Preconditions:  A list object exists
  // Postconditions: Returns true if the list contains no Nodes and false if the list contains at least one Node.
  // ******************************************************************************************
  // ******************************************************************************************
  void head_insert(const Node<Pizza>::value_type &value);
  // Summary: This function inserts a new Node at the beginning of the list.
  // Preconditions:  A head_ptr exists and a new value has been passed in.
  // Postconditions: A new Node has been added to the beginning of the list with the value in the data_field at the head of the list.
  // ******************************************************************************************
  // ******************************************************************************************


  void head_remove();
  // Summary: This function removes the Node at the beginning of the list.
  // Preconditions: There is a list with head_ptr pointing to the beginning
  // of the list.
  // Postconditions: We have a list with the previous head Node of the list
  // removed.
  // *********************************************************************
  // *********************************************************************

  void clear_list();
  // Summary: This function empties the list.
  // Preconditions: There is a current list.
  // Postconditions: list has been cleared of Nodes. head_ptr now is NULL.
  // *********************************************************************
  // *********************************************************************

  void take_order();
  // Summary: This function will take all info from user and store in the variables
  // also, will create the pizza nodes and store them in a lincked list.
  //Precondition: a Order object instantiated.
  // Postconditions: an order object is populated with pizza nodes and customer info.

  void print_order();
  // Summary: this function will print summary of all object info.

  bool is_ready();
  // Summary: this function will check if an order is ready.
  // Preconditons: object has been created and pizza list is not empty
  // Postconditions: a bool is returned after comparing the order_time to the cook_time

  bool is_delivered();
  // Summary: this function will check if an order was delivered.
  // Preconditons: object has been created and pizza list is not empty
  // Postconditions: a bool is returned after comparing the order_time to the cook_time+deliverry_time;

  ~Order();
  // Summary: The destructor empties the list.
  // *********************************************************************

private:
  int cook_time;
  unordered_map<char, int> cooking_time{{'s', 10},{'m', 15},{'l', 20}};
  const string toppings[Topping_list_size]{"End",
                            "Artichoke hearts",
                            "Capers",
                            "Tomatoes",
                            "Mushrooms",
                            "Onions",
                            "Olives",
                            "Red peppers",
                            "Roasted Garlic",
                            "Roasted peppers",
                            "Sun dried tomatoes",
                            "Sweet corn",
                            "Feta Cheese",
                            "Extra Cheese",
                            "Bacon",
                            "Pepperoni",
                            "Proscuitto",
                            "Sausage",
                            "Shrimps",
                            "Anchovies"};
  string customer_name;
  string customer_phone;
  Node<Pizza> *head_ptr; // Points to front of list
  Node<Pizza> *tail_ptr; // Points to end of list
  size_type pizza_count; // holds the number of Nodes in the list
  time_t order_time =0;     //store the time when the order was placed

  void set_start_time() { order_time = time(NULL); };
  // Summary: a timestamp will be created and stored
  // *********************************************************************

  void add_pizza();
  void print_topping_list() const;
};

