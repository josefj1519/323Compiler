#include "var_checker.h"
#include <iostream>

namespace{
    bool CheckIfValidCharacter(const char &character){
        return  ((character>=65 && character <= 90) || 
        (character>=97 && character<=122) || character == '_');
    }
}

namespace varcheckercc{


 bool  CheckIfValidVariableName(const std::string &potential_variable){
     if(potential_variable.empty()){
         return false; 
     }
     bool first_character = true;
    for(const auto &character : potential_variable){
        if(first_character){
            if(!CheckIfValidCharacter(character)){
                return false;
            }
           first_character = false;
        }
        else if(!(CheckIfValidCharacter(character) || (character>=48 && character<=57))){
           return false;
       }
    }
    return true;
 }

}