//code for transaction struct here
#include "transaction.h"
#include <sstream>
#include <iomanip>

using std::string;
using namespace std;

string transaction::transaction_info() {
    
    std::ostringstream out;
    out << "Transaction #: " << transaction_number << "\nCustomer:" << customer.person_info() 
        << "\nProduct: " << purchased_item.product_info() << "\nQuantity: " << quantity << "\n";
    
    return out.str();
}
