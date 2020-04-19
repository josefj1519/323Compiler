// 323-Project-Part01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main()
{
    char current_char;
    char prev_char = '?'; 
    std::fstream fin("source.txt", std::fstream::in);
    std::string input_string;
    //std::fstream fout("output.txt", std::fstream::out);


    while (fin >> std::noskipws >> current_char) {
        
        
        if (current_char != ' ') {

            if (current_char == '(') {
                
                prev_char = current_char;
                // get the next character
                fin >> std::noskipws >> current_char;

                // it's a comment
                if (current_char == '*' && prev_char == '(') {
                    
                    // continue reading chars until you read end comment
                    while (fin >> std::noskipws >> current_char) {
                        // if you read the end, exit the loop
                        if (current_char == ')' && prev_char == '*') {                           
                            break;
                        }
                        // update b_expression vars for above if statement
                        prev_char = current_char;
                    }
                }
                // its not a comment
                else {
                    std::cout << prev_char << current_char;
                }
            }

            else if (current_char == 'M') {
                std::cout << current_char;
                std::cout << " ";
            }

            else if (current_char == ',') {
                
                std::cout << current_char;
                std::cout << " ";
            }

            else if (current_char == ':') {
                std::cout << " : ";
            }

            else if (current_char == '=') {
                std::cout << " = ";
            }

            else {
                std::cout << current_char;
            }     
        }

        prev_char = current_char;
    }    
        // check for empty space
        if (current_char == ' ') {
            
            // get the next char
            fin >> std::noskipws >> current_char;

            // if its more empty space, start skipping chars
            if (current_char == ' ') {
                while (fin >> std::noskipws >> current_char) {
                    if (current_char != ' ') {
                        break;
                    }
                }
            }
        }

        // check for start of a comment
        if (current_char == '(') {

            // do not write it down b4 getting next char
            fin >> std::noskipws >> current_char;

            // verify that it is indeed a comment
            if (current_char == '*') {              

                // keep skipping chars until reading the end of a comment
                while (fin >> std::noskipws >> current_char) {

                    // check for ending of comment
                    if (current_char == '*') {

                        // get the next char
                        fin >> std::noskipws >> current_char;

                        // if it is ending a comment, exit this loop
                        if (current_char == ')') {
                            
                            fin >> std::noskipws >> current_char;
                            break;
                        }
                    }
                }
            }
            // if its not a comment, prepend the parenthesis to the next char
            else {
                std::cout << '(' << current_char;
            }
        }
        
        std::cout << current_char;
        prev_char = current_char;

        //std::cout << "current char: " << current_char << std::endl;
        //std::cout << "prev char: " << prev_char << std::endl;
    
    fin.close();

    return 0;
}

