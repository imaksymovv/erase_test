#include <iostream>
#include <vector>

class Test {
 public:
     Test(){ 
      std::cout << "Default constructor" << std::endl;
     }

     Test(const Test&) {
         std::cout << "Copy constructor" << std::endl;
     }
     Test(Test&&) noexcept {
         std::cout << "Move constructor" << std::endl;
     }
     Test &operator=(const Test&) { 
         std::cout << "Copy assign" << std::endl;
         return *this;
     }
     Test& operator=(Test&& other) {
       std::cout << "Move assign" << std::endl;
       return *this;
     }
     ~Test() {
         std::cout << "Destructor" << std::endl;
     }
};


int main() {
  Test number;
  Test number1;
  Test number2;
  Test number3;
  std::cout << "Something" << std::endl;
  std::vector<Test> test{number, number1, number2, number3, std::move(Test())};
  test.emplace_back(Test());
  std::cout << "Something" << std::endl;
  auto it = test.erase(test.begin() + 2);
  std::cout << "Something" << std::endl;
  return 0; 
}