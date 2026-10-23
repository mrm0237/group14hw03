//code for transaction struct here
#include "transaction.h"
#include <sstream>
#include <iomanip>

using std::string;
using namespace std;

string transaction::transaction_info() {
    
    std::ostringstream out;
    out << "Customer Name: " << customer_name << "\nProduct Name: " << product_name
        << "\nQuantity: " << quantity << "\nTotal Price: $" << std::fixed << std::setprecision(2) << total_price;
    
    return out.str();
}
