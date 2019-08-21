#ifndef STRING.HPP
#define STRING.HPP

#include<cassert>
#include<iostream>

class String{
public:
    String();
	String(char c);
	String (char ch[]);
	String(const String& rhs);
	~String();
	void swap(String& rhs);				//constant time swap
	String& operator = (String);
	
	
	int length() const;
	int capacity() const;
	
	char& operator[](int);				//non-constant
	char operator[](int) const;		//constant
	
	bool operator == (const String& rhs) const;
	bool operator < (const String& rhs) const;
	
	String operator+(const String& rhs) const;
	String& operator += (const String& rhs);
	
	String substr(int start, int end) const;
	int findch(int pos, char ch) const;
	int findstr(int pos, const String& s) const;
	std::vector<String> split(char split) const;

	friend std::istream& operator >> (std::istream& in, String& s);
 	friend std::ostream& operator << (std::ostream& out, const String& s); 
	
private:
    char* str;
	int stringSize;
	
	String(int cap);
	String(int cap, const char* s);	
	String(int cap, const String& actual);
	void resetCapacity(int cap);
};

#endif
