#include <iostream>
#include <iomanip>

#include "Surgery.h"
int main() {
    Surgery s1("S001", 90);
    Surgery s2("S002", 120);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << s1.Equals(s2) << std::endl;          // Output: false
    std::cout << "NotEquals: " << s1.NotEquals(s2) << std::endl;          // Output: true
    std::cout << "GreaterThan: " << s1.GreaterThan(s2) << std::endl;      // Output: false
    std::cout << "GreaterThanEquals: " << s1.GreaterThanEquals(s2) << std::endl;          // Output: false
    std::cout << "LessThan: " << s1.LessThan(s2) << std::endl;          // Output: true
    std::cout << "LessThanEquals: " << s1.LessThanEquals(s2) << std::endl;  // Output: true

    return 0;
}
