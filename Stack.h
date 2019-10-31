#include "List.h"
#include <cstddef>

template<typename T>
class Stack
{
  protected:
     List<T> c;
	 
  public:
  
	Stack(){}
	
	Stack(std::initializer_list<T> link): c(link){}
	
	T& top(){return c.front();}
	
	const T& top() const{return c.front();}
	
	void push(const T& w){c.push_front(w);}
	
	void pop(){c.pop_front();}
	
	size_t size() const{return c.size();}
	
	bool empty() const{return c.empty();}
	Stack<T>& operator=(const Stack<T>& _stack)
	{
		c = _stack.c;
		return *this;
	}
	template<typename R>
	friend bool operator==(const Stack<R>&, const Stack<R>&);
	
	template<typename R>
	friend bool operator!=(const Stack<R>&, const Stack<R>&);
	
};

template<typename R>

bool operator==(const Stack<R>& x, const Stack<R>& y)
{
	return x.c == y.c;
}

template<typename R>
bool operator!=(const Stack<R>& x, const Stack<R>& y)
{
	return x.c != y.c;
}