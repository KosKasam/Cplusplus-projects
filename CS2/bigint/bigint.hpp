#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int MAX_SIZE=100;

class bigint{
public:
  bigint();
  bigint(int);
  bigint(const char[]);


  friend std::ostream& operator << (std::ostream& out,const bigint& rhs);
  friend std::istream& operator >> (std::istream& in, bigint& rhs);

  bool operator == (const bigint&) const;
  bigint operator + (bigint rhs) const;

  //bigint operator+(const bigint& rhs)const;
  int operator[](const int start);
  //int operator[](int) const;

private:
  int flexibleArray[MAX_SIZE], size;
};

#endif
