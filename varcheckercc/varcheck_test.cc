#include <iostream>
#include "var_checker.h"

int main(){

  std::cout << "Dino " << varcheckercc::CheckIfValidVariableName("Dino") << std::endl;
  std::cout << "1Dino " << varcheckercc::CheckIfValidVariableName("1Dino") << std::endl;
  std::cout <<  "_ " << varcheckercc::CheckIfValidVariableName("_") << std::endl;
  std::cout << "Di no " << varcheckercc::CheckIfValidVariableName("Di no") << std::endl;
  std::cout << "Din0w " << varcheckercc::CheckIfValidVariableName("Din0w") << std::endl;
  std::cout << "22 " << varcheckercc::CheckIfValidVariableName("22") << std::endl;
  std::cout << "empty string " << varcheckercc::CheckIfValidVariableName("") << std::endl;
  std::cout << " Dino " << varcheckercc::CheckIfValidVariableName(" Dino") << std::endl;
  std::cout << "space " << varcheckercc::CheckIfValidVariableName(" ") << std::endl;
  std::cout << "ab_123 " << varcheckercc::CheckIfValidVariableName("ab_123") << std::endl;
  
  return 0;
}