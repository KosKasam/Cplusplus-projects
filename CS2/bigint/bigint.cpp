#include "bigint.hpp"
#include <iostream>


bigint::bigint(){
  for(int i = 0; i < MAX_SIZE; ++i)
    flexibleArray[i] = 0;
}

bigint::bigint(int digCarrier) {
  int i = 0, c = 0;
  while (i<MAX_SIZE){
    flexibleArray[i] = 0;
    ++i;
  }
  while (digCarrier != 0) {
    flexibleArray[c] = digCarrier % 10;
    ++c;
    digCarrier = digCarrier / 10;
  }
  size = c;
}

std::ostream& operator << (std::ostream& out, const bigint& rhs) {
  int i = 0;
  if (rhs.size >= 1) {
    while(rhs.flexibleArray[i] = MAX_SIZE - 1){
      --i;
    while (i >= 0) {
      out << rhs.flexibleArray[i];
      --i;
    }
  }
 else{
      out << rhs.flexibleArray[i];
  }
  return out;
}

bool bigint::operator==(const bigint& rhs) const {//equals operator compares the index of variable array to null
  int i = 0;                                //and rhs to null, if that's not equal false, if equal iterates
  while (i < MAX_SIZE){
    if (flexibleArray[i] != rhs.flexibleArray[i]) return false;
    i++;
  }
  return true;
}

bigint::bigint(const char charDelivery[]) {
  int length = 0;
  int tmp = 0;
  for(int i=0; i<MAX_SIZE; ++i){
    flexibleArray[i]=0;
  }
  while (charDelivery[length] != '\0'){
    ++length;
        }
  --length;
  tmp = length;
  int i = 0;
  while(i < MAX_SIZE && tmp >= 0) {
    int num = charDelivery[tmp] - '0';
    flexibleArray[i] = num;
    tmp = tmp - 1;
    ++i;
  }
  size = i;
}

std::istream& operator >> (std::istream& in, bigint& rhs){
  char  semicolonSeeker;
  char num[MAX_SIZE];
  int i = 0;
  if(!in.eof())
    in >> semicolonSeeker;
  while((!in.eof()) && (semicolonSeeker != ';') && (semicolonSeeker != ' ')){
    num[i] = semicolonSeeker;
    ++i;
   in >> semicolonSeeker;
  }
  num[i] = '\0';
  rhs = bigint(num);
  return in;
}

bigint bigint::operator + (bigint rhs)const{
  int remainder = 0, carry = 0, number = 0;
  for(int i = 0; i < MAX_SIZE; ++i){
    number = flexibleArray[i] + rhs.flexibleArray[i] + carry;
    remainder = number % 10;
    carry = number/10;
    if((size) != rhs.size){
      rhs.flexibleArray[i] = remainder;
      rhs.flexibleArray[i+1] = carry;
      break;
    }
    rhs.flexibleArray[i] = remainder;
  }
  return rhs;
}

int bigint::operator[](const int start){
  return flexibleArray[start];
}
