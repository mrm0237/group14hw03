//code for store class here
//include everything we need and get the standard namespace
#include <sstream>
#include <iostream>
#include <iomanip>
#include "store.h"

using namespace std;

class Store{ 
  public:
    Store();
  private:   // parameters
    int num_customers_;
    Customer* customers_;
    int num_products_;
    Product* products_;
    int num_transactions_;
    Transaction* transactions_;
  Store::Store() { // default constructor; set everything to 0 or null
    num_customers_ = 0;
    customers_ = nullptr;
    num_products_ = 0;
    products_ = nullptr;
    num_transactions = 0;
    transactions_ = nullptr;
  }
// Make setters and getters for the private variables
  void num_products(int product_count) {
    num_products_ = product_count;
  }
  int num_products() {
    return num_products_;
  }

  void num_customers(int customer_count) {
    num_customers_ = customer_count;
  }
  int num_customers() {
    return num_customers_;
  }

  void num_transactions(int transaction_count) {
    num_transactions_ = transaction_count;
  }
  int num_transactions() {
    return num_transactions_;
  }
  // Now time for the methods! add methods for each parameter, update method for customer,
  // get method for product and transaction, make_purchase method
  bool add_product(product item) {
    // See if the product exists in the store
    // This method is bool because if the product exists, we'll return false
    for (int i = 0; i < num_products; i++) {
      if (products_[i].name() = item.name) {
        return false; // Product exists, so we don't need to add it
      }
    }
    // Add the product to the store -> new array of size++
    product* new_products = new product[num_products_ + 1];
    for (int i = 0; i < num_products_; i++) { // add old products list to new
      new_products[i] = products_[i];
    }
    new_products[num_products_] = item;
    delete[] products_;         // out with the old
    products_ = new_products;   // in with the new
    num_products_++;
    return true;
  }
    
  bool add_customer(Person customer) {
    // See if the customer already exists in the store
    for (int i = 0; i < num_customers_; i++) {
      if (customers_[i].name() == customer.name()) {
        return false;  // Customer exists, so we don't need to add them
      }
      // Add the customer to the store
      Person* new_customers = new Person[num_customers_ + 1];
      for (int i = 0; i < num_customers_; i++) { // Populate new array
        new_customers[i] = customers_[i];
      }
      new_customers[num_customers_] = customer;
      delete[] customers_;         // out with the old,
      customers_ = new_customers;  // in with the new
      num_customers_++;
      return true;
  }
  bool update_customer(int index, Person customer) {
    if (index < 0 || index >= num_customers_) {
      return false;  // check that index is in amount of customers array
    }
    customers_[index] = customer;  // customer at that index is changed to this customer
    return true;
  }

  product get_product(int index) {
    if (index < 0 || index >= num_products_) {    
      throw std::out_of_range("Invalid product index"); 
    }                          // if products_ has index index,
    return products_[index];   // output products_[index]
  }

    bool add_transaction(transaction ntranscation) {
      // See if the transaction already exists in the store
      for (int i = 0; i < num_transactions_; i++) {
        if (transactions_[i].id() == transaction.id()) {
          return false;  // Transaction already exists
        }
      }
      // Add the transaction to the store
      transaction* new_transactions = new transaction[num_transactions_++];
      for (int i = 0; i < num_transactions_-1; i++) {
        new_transactions[i] = transactions_[i];
      }
      new_transactions[num_transactions_] = transaction;
      delete[] transactions_;
      transactions_ = new_transactions;
      return true;
    }



}





