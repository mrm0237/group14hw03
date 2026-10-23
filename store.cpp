//code for store class here
//include everything we need and get the standard namespace
#include <sstream>
#include <iostream>
#include <iomanip>
#include "store.h"

using namespace std;

class Store{ 
  public:
    Store();  // calls Store from Store.h
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
  // Now time for the constructors! ADD methods for each parameter, UPDATE method for customer,
  // GET method for product and transaction, make_purchase method
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
    new_products[num_products_++] = item;  // make the new item be in the right place
                                           // and increment num_products
    delete[] products_;         // out with the old
    products_ = new_products;   // in with the new
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
      new_customers[num_customers_++] = customer;
      delete[] customers_;         // out with the old,
      customers_ = new_customers;  // in with the new
      return true;
  }
  bool update_customer(int index, Person customer) {
    if (index < 0 || index >= num_customers_) {
      return false;  // check that index is in bounds of customers array
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
      // Add the transaction to the store by making a new array with num_transactions_ + 1 items
    transaction* new_transactions = new transaction[num_transactions_];
      for (int i = 0; i < num_transactions_; i++) {
        new_transactions[i] = transactions_[i];
      }
      new_transactions[num_transactions_++] = transaction; // new transaction array
      delete[] transactions_;
      transactions_ = new_transactions;
      return true;
    }

    transaction get_transaction(int index) {
      if (index < 0 || index >= num_transactions_) {
        throw std::out_of_range("Invalid transaction index");
      }
      return transactions_[index];
    }

    bool make_purchase(Person customer, product item, int amount) {
      // See if the customer exists in the store
      int customer_index = -1;
      for (int i = 0; i < num_customers_; i++) {
        if (customers_[i].name() == customer.name()) {
          customer_index = i;
          break;
        }  
      }  
      if (customer_index == -1) {
        return false; // Nothing has changed in if statement; customer does not exist 
      }

      // See if the product exists
      int product_index = -1;
      for (int i = 0; i < num_products_; i++) {
        if (products_[i].name() == item.name()) {
          product_index = i;
          break;
        }
      }
      if (product_index == -1) {
        return false; // Product does not exist
      }  

      // Make a new transaction
      transaction new_transaction(customer, item, amount);
      return add_transaction(new_transaction);
    }

    // Information methods: return the info of the store's products, transactions, purchases, and all store info
    // Returns a string listing all products associated with the store
    string product_info() {
      std::ostringstream oss;
      // Output the Product Name and Price for every product
      for (int i = 0; i < num_products_; i++) {
        oss << "Product Name: " << products_[i].name();
        oss << ", Price: " << products_i.price() << endl;
      }
    return oss.str();
    }
    // Returns a string of all the transactions the store has made
    string transaction_info() {
      std::ostringstream oss;
      // Output the Transaction ID, Customer, Product, and Amount for each transaction
      for (int i = 0; i < num_transactions_; i++) {
        oss << "Transaction ID: " << transaction_[i].id();
        oss << ", Customer: " << transactions_[i].customer().name();
        oss << ", Product: " << transactions_[i].product().name();
        oss << ", Amount: " << transactions_[i].amount() << endl;
    }
    return oss.str();
  }

    string store_info() {  // Return all the numerical info from the store
      std::ostringstream oss;
      // Output the number of customers, products, and transactions for the store
      oss << "Number of Customers: " << num_customers_ << endl;
      oss << "Number of Products: " << num_products_ << endl;
      oss << "Number of Transactions: " << num_transactions_ << endl;
      return oss.str();
    }

    string purchase_history(Person customer) {
      std::ostringstream oss;
      // Output the Transaction ID, Product, and Amount for each transaction 
      for (int i = 0; i < num_transactions_; i++) {
        if (transactions_[i].customer().name() == customer.name()) {
          oss << "Transaction ID: " << transactions_[i].id();
          oss << ", Product: " << transactions_[i].product().name();
          oss << ", Amount: " << transactions_[i].amount() << endl;
        }
      }
      return oss.str();
    }
}





