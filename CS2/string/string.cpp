#include "string.hpp"


String::String(){
	str[0] = '\0';
	//or 
	str[0] = 0;
}

String::String(char c){
	str[0] = c;
	str[1] ='\0';
}

// identical to below 
//String::String(char *ch )

String::String(char ch[]){
    int i = 0;

    while(ch[i] != '\0'){
        str[i] = ch[i];
        i++;
	}		
    str[i] = '\0';	
}


int String::length() const{
	int i = 0;
	while(str[i] != '\0')
		i++
	return i;	
}

int String::capacity() const{
	return STRING_SIZE - 1;
}

char& String::operator[](int i){
    return str[i];	
}

char& String::operator[](int i) const{
	return str[i];
}


bool String::operator==(const String& rhs) const{
	int i = 0;
	while((str[i]!='\0')&&(rhs.str[i]!='\0')){
		if(str[i] != rhs.str[i]) return false;
		++i;
	}
	return ((str[i] == '\0') && (rhs.str[i] == '\0'));
}

bool String::operator<(const String& rhs) const{
	int i = 0;
	while((str[i] != '\0') && (rhs.str[i] != '\0') && (str[i]) == rhs.str[i])
		++i;
	
	if((str[i] == 0) && (rhs.str[i] == 0)) return false;		//str1 == str2
	if (str[i] == 0) return true;									   // "aa" < "aaaaaaa"
	if(str[i] < rhs.str[i]) return true;							   // "aa" < "ab"
	return false;
}

String String::operator+(const String& rhs) const{
	int offset = length();
	//String result(*str);											//lhs stored in result
	String result;

	int i = 0;
	while(rhs.str[i] != '\0'){
		result.str[i+offset];
		++i;
		if(i+offset >= STRING_SIZE-1) break;
	}
	result.str[offset+i] = '\0';
	return result;
}


std::istream& operator>>(std::istream& in, String& s){
	in >> s.str;
	return in;
}

std::ostream& operator << (std::ostream& out, const String& s){
	out << s.str; 					//the array is pointing to the first character of the array until \0
	return out;	
