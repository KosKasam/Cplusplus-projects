template <typename T>
class Node{
public:
	Node();
	Node(const T& x){data = x; next = 0;}

	T data;
	Node<T> *next;
};

template <typename T>
class Stack{
public:
	Stack(){tos = 0;}
	Stack(const Stack<T>& rhs);
	void swap(const Stack<T>& rhs);
	Stack<T>&operator = (Stack<T> rhs);
	~Stack();
	
	void push(const T& item);
	T pop();
	T push();
	T top() const;
	bool isEmpty() const{return tos == 0;}
	bool isFull() const;

private:
	Node<T> *tos;
};

template <typename T>
Stack<T>::Stack(const Stack<T>& actual){
	Node<T>* bottom;
	Node<T>* temp = actual.tos;
	
	tos = 0;
	
	while(temp != 0){
		if(tos == 0){
			tos = new Node<T>(temp -> data);
			bottom = tos;
		}
		else{
		bottom -> next = new Node<T>(temp -> data);
		bottom = bottom -> next;
		}
		temp = temp -> next;	
	}	
}

template <typename T>
Stack<T>::~Stack(){
	Node<T>* temp;
	while(tos != 0){
		temp = tos;
		tos = tos -> next;
		delete temp;
	}
}

template <typename T>
void Stack<T>::swap(Stack<T>& x){
	Node<T>* temp = tos;
	tos = x.tos;
	x.tos = temp;
}

template <typename T>
Stack<T>& ::operator = (Stack<T> rhs){
	swap(rhs);
	return *this;
}

template <typename T>
bool Stack<T>::isFull() const{
	using std::nothrow;
	Node<T>* temp = new (nothrow) Node<T>;
	
	if(temp == 0)
		return true;
	else
		delete temp;

	return false;
}

template <typename T>
T Stack <T>::top () const{
	assert(top != 0);
	return tos -> data;
}

template <typename T>
T Stack<T>::pop(){
	assert(tos != 0);
	T result = tos -> data;
	
	Node<T>* temp = tos;
	tos = tos -> next;
	
	delete temp;
	return result;
}

template <typename T>
void Stack<T>::push(const T& newItem){
	assert(!isFull());
		
	Node<T>* temp = new Node<T>(newItem);
	temp -> next = tos;
	tos = temp;
}
