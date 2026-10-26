//implementation code for credit_card struct here
#include "credit_card.h"
#include <sstream>
#include <iomanip>
#include <string>

using std::string;

string credit_card::credit_card_info() {
    std::ostringstream out;

    out << "Credit card number: " << cc_number
        << "\nCredit Card Limit: $" << std::fixed << std::setprecision(2) << limit
        << "\nCredit Card Balance: $" << current_balance << "\n\n";

    return out.str();
}

bool credit_card::make_purchase(double purchase_amount) {
    if (current_balance + purchase_amount <= limit) {
        current_balance += purchase_amount;
        return true;
    }

    return false;
}

bool credit_card::make_payment(double payment_amount) {
    if (payment_amount > current_balance) {
        return false;
    }

    current_balance -= payment_amount;
    return true;
}
