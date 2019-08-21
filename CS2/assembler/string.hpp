#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <vector>

class String {
public:
  String        ();                               //Empty string
  String        (char);                           //String('x')
  String        (const char[]);                   //String("abc")
 String        (const String&);                  //Copy Constructor
  ~String       ();                               //Destructor
  void    swap          (String&);                        //Constant time swap
  String& operator=     (String);                         //Assignment Copy
  char&   operator[]    (int);                            //Accessor/Modifier
  char    operator[]    (int)                     const;  //Accessor
  int     capacity      ()                        const;  //Max chars that can be stored (not including null)
  int     length        ()                        const;  //Actual number of chars in string
  String  operator+     (const String&)           const;
  String& operator+=    (const String&);
  bool    operator==    (const String&)           const;
  bool    operator<     (const String&)           const;

  String  substr        (int, int)                const;  //The sub-string from staring position to ending position
  int     findch        (int,  char)              const;  //Find location of charater starting at a position
  int     findstr       (int,  const String&)     const;  //Find location of str starting at a position
  std::vector<String>   split (char split)        const;


  friend  std::istream& operator>>(std::istream&, String&);
  friend  std::ostream& operator<<(std::ostream&, const String&);

private:
  String        (int);                            //String(10) - size of 10.
  String        (int, const char[]);              //String(10, "abc") - Size 10 with "abc"
  void    resetCapacity (int);                            //Resets capacity to be N

  char    *str;                                           //Pointer to char[]
  int     stringSize;                                     //Size includes NULL terminator
};

String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

#endif

