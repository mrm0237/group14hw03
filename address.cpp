//implementation code for address struct here
#include "address.h"
#include <sstream>
#include <iostream>

using namespace std;

class Address {
  
  public:
    Address();
  private:
    string address_line1;
    string address_line2;
    string city;
    string state;
    string zip;

  string address_info() {
    std::ostringstream oss;
    /* Example: 
    Shelby Center for Engineering Technology
    357-359 W Magnolia Ave
    Auburn, AL, 36830
    */
    oss << address_line1 << endl;
    if (!address_line2.empty()) {
      oss << address_line2 << endl;
    }
    oss << city << ", " << state << " " << zip;
  }
}
