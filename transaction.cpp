//code for transaction struct here
#include "transaction.h"
#include <sstream>
#include <iomanip>

using std::string;
using namespace std;

string transaction::transaction_info() {
    
    std::ostringstream out;
    out << "Transaction #: " << transaction_number << "\n"
        << "Customer:\n" << customer.person_info()  << "Product:\n" << purchased_item.product_info() 
        << "Quantity: " << quantity << "\n";
    
    return out.str();
}
