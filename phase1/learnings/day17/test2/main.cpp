#include <iostream>
#include <iomanip>

#include "Surgery.h"
int main() {
    Surgery s1("S001", 90);
    Surgery s2("S002", 120);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << Equals(s1,s2) << std::endl;          // Output: false
    std::cout << "NotEquals: " << NotEquals(s1,s2) << std::endl;          // Output: true
    std::cout << "GreaterThan: " << GreaterThan(s1,s2) << std::endl;      // Output: false
    std::cout << "GreaterThanEquals: " << GreaterThanEquals(s1,s2) << std::endl;          // Output: false
    std::cout << "LessThan: " << LessThan(s1,s2) << std::endl;          // Output: true
    std::cout << "LessThanEquals: " << LessThanEquals(s1,s2) << std::endl;  // Output: true

    return 0;
}
