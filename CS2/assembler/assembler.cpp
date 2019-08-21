#include <fstream>
#include "stack.hpp"
#include "string.hpp"

void assembly(std::ifstream&, std::ofstream&);
String intStr(int);
String getToken(std::ifstream&);
void directive();
String  evaluate(const String&,const String&,const String&, int &);
String postfix(const String&);

int main(int argc, char const* argv[]){
  String infix;
  if(argc == 1){
    std::cout << "Input and Output files are required" << std::endl;
    directive();
    return -1;
  }

  std::ifstream input(argv[1]);
  std::ofstream assembly(argv[2]);

  String result;
  if(argc == 2){
    if(input.is_open()){
      while(!input.eof()){
        infix = getLine(input);
        result = postfix(infix);
        assembly(result);
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
        assembly(result);
        assembly << result << std::endl;
      }
    }
    else if(!input.is_open()) {
      std::cout<< "Cannot be opened";
      return -1;
    }
  }
  input.close();
  assembly.close();
  return 0;
}

void assembly(/*std::ifstream& in, std::ofstream& out*/ const String& postfix){
  stack<String> sStr;
  std::vector<String> vec = postfix.split(' ');
  String lhs, rhs, op, token, expr, temp;
  int n = 1;

  while(!in.eof() || !sStr.empty()){
  /*if(!in.eof()){
      token = getToken(in);
    }
    else {
      break;
    }

    if(token == ";"){
      out << "\n";
      n = 1;
    }
*/
    if(!in.eof() && token != "+" && token != "-" && token != "*" && token != "/"/* && token != "(" && token != ")"*/){
      //assert(!(sStr.empty()));
      sStr.push(token);
    }else if (!in.eof()){
      rhs = sStr.pop();
      lhs = sStr.pop();

      //temp = "TMP" + intStr(n++);
      expr = evaluate(lhs, rhs, op, n);
      //out << op << rhs << "\n";
      //out << expr << std::endl;
      //      sStr.push(expr/*temp*/);
    }
  }
}


String evaluate(const String& lhs, const String& rhs, const String& op, int& n){
  String operation, result;
 if(op == '/')
    operation = "DV";
  if(op == '*')
    operation = "ML";
  if(op == '-')
    operation = "SB";
  if(op == '+')
    operation = "AD";

  String temp = "TMP" + intStr(++n);

  std::cout << "LD\t" << lhs << std::endl;
  std::cout << operation << rhs << std::endl;
  std::cout << "ST\t" << /*"TMP" << ++n*/ temp  << std::endl;

  //return "TMP" + (--n)/*intStr(n)*/;
  return  "TMP" + intStr(--n);
}

String intStr(int n){
  if (!n)
    return "0";

  //  String result;
  char result[0];
  do{
    //    n = n % 10;
    //result +=  n + 48;
    //result += friend String::String(n);
    n /= 10;
    //char (n + 48);
  } while (n > 0);

  return result;
}
/*
String getToken(std::ifstream& in){
  String result;
  char token = '\0';
  int i = 0;

  while((token != ' ') && (!in.eof())){
    in.get(token);
    if(token == ';')
      return ";";
    else if(token != ' ')
      result += token;
    ++i;
  }
  return result;
}*/

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
   // std::cout <<"line: " << line << "\n";
  }
  return line;
}

void directive(){
  std::cerr << "Insert: postfix [input file] [output file]\n";
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
