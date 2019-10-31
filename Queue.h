#include "List.h"
#include <cstddef>

template<typename T>
class Queue
{
  protected:
     List<T> c;
	 
  public:
	Queue(){}
	
	Queue(std::initializer_list<T> link): c(link){}
	
	T& front(){return c.front();}
	
	T& back(){return c.back();}
	
	const T& front() const{return c.front();}
	
	const T& back() const{return c.back();}
	
	void push(const T& w){c.push_back(w);}
	
	void pop(){c.pop_front();}
	
	size_t size() const{return c.size();}
	
	bool empty() const{return c.empty();}
	
	Queue<T>& operator=(const Queue<T>& _queue)
	{
		c = _queue.c;
		return *this;
	}
	
	template<typename R>
	friend bool operator==(const Queue<R>&, const Queue<R>&);
	
	template<typename R>
	friend bool operator!=(const Queue<R>&, const Queue<R>&);
	
};

template<typename R>
bool operator==(const Queue<R>& x, const Queue<R>& y)
{
	return x.c == y.c;
}
template<typename R>
bool operator!=(const Queue<R>& x, const Queue<R>& y)
{
	return x.c != y.c;
}