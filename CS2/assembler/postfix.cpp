#include "string.hpp"
#include "stack.hpp"
#include <fstream>
#include <iostream>
#include <vector>

String getLine(std::ifstream&);
void directive();
String postfix(const String&);

int main(int argc, char* argv[]){
  String infix;
  if(argc == 1){
    std::cout << "Input and Output files are required" << std::endl;
    directive();
    return -1;
  }

  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);

  String result;
  if(argc == 2){
    if(input.is_open()){
      while(!input.eof()){
        infix = getLine(input);
        result = postfix(infix);
        std::cout << result << std::endl;
      }
    }
    else if(!input.is_open()) {
      std::cout<< "Cannot be opened";
      return -1;
   }
  }
  else if(argc == 3){
    if(input.is_open()){
      while(!input.eof()){
        infix = getLine(input);
        result = postfix(infix);
        output << result << std::endl;
      }
    }
    else if(!input.is_open()) {
      std::cout<< "Cannot be opened";
      return -1;
    }
  }
  input.close();
  output.close();
  return 0;
}


void directive(){
  std::cerr << "Insert: ./postfix [input file] [output file]\n";
}

String postfix(const String& infix){
  std::vector<String> stringOTokens = infix.split(' ');
  stack<String> z;
  int i = 0;
  String lhs, rhs, op;
  while(stringOTokens[i] != ";") {
   if (stringOTokens[i] == ")") {
      rhs = z.pop();
      op = z.pop();
      lhs = z.pop();
      z.push(lhs + " " + rhs + " " + op);
    }else if (stringOTokens[i] != "(") {
      z.push(stringOTokens[i]);
    }
    ++i;
  }
  return z.pop();
}

String getLine(std::ifstream& in){
  String line;
  if(in.is_open()){
    //    String line;
    char  ch;
    while((!in.eof()) && (ch != '\n')){
        //    String line;
        in.get(ch);
        if((ch != '\n') && (ch != '\r'))
          line += ch;
    }
    std::cout <<"line: " << line << "\n";
  }
  return line;
}
