#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <cstddef>
#include <initializer_list>

template<typename T>
class List
{
	private:

	typedef struct llist {
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_head; 
	llist *_tail;
	size_t _size;
	
	void reccopy(const llist *ptr)
	{
		if (ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->value);
		}
	}

	public:
	
//--- Default Constructor ------------------------------
	List()
	{
		_head = 0;
		_tail = 0;
		_size = 0;
	}
	
//--- Copy Constructor ---------------------------------
	List(const List& other)
	{
		clear();
		reccopy(other._head);
	}
	
	List(const std::initializer_list<T>& link)
	{
		_head = 0;
		_tail = 0;
		_size = 0;
		for(auto value : link)
			push_back(value);
	}
	
//--- Destructor ---------------------------------------
	~List()
	{
		while(!empty())
			pop_front();
	}
	
//--- Operator Equal -----------------------------------
	List& operator=(const List& b)
	{
		if(!empty())
			clear();
		const llist *copier = b._head;
		while(copier != NULL)
		{
			push_back(copier->value);
			copier = copier->next;
		}
		_size = b.size();
		return *this;	
	}
	
//--- Empty --------------------------------------------------------------
	bool empty() const
	{
		if(_head == 0 && _tail == 0)
			return true;
		return false;
	}
	
//--- Size ---------------------------------------------------------------
	size_t size() const
	{
		return _size;
	}
//--- Clear --------------------------------------------------------------
	void clear()
	{
		while(empty() == false)
		{
			pop_back();
		}
		_size = 0;
	}
	
//--- Reference Front & Back ---------------------------------------------
	T& front()
	{
		return _head->value;
	}
	T& back()
	{
		return _tail->value;
	}
	
	const T& back() const
	{
		return _head->value;
	}
	const T& front() const
	{
		return _tail->value;
	}
	
//--- Push Functions -----------------------------------------------------
	void push_front(const T& value)
	{
		llist *newFront = new llist;
		newFront->value = value;
		newFront->next = _head;
		newFront->prev = 0;
		if (_head != 0)
			_head->prev = newFront;
		if (_tail == 0)
			_tail = newFront;
		_head = newFront; 
		_size++;
	}
	
	void push_back(const T& value)
	{
		llist *newBack = new llist;
		newBack->value = value;
		newBack->next = 0;
		newBack->prev = _tail;
		if(_tail != 0)
			_tail->next = newBack;
		if(_head == 0)
			_head = newBack;
		_tail = newBack;
		_size++;
	}
	
//--- Pop Functions -------------------------------------------------------
	void pop_front()
	{
		llist *front = _head;
		_head = _head->next;
		if(_head)
			_head->prev = _head->prev->prev;
		else
			_tail = 0;
			
		delete front;
		_size--;
	}
	
	void pop_back()
	{
		llist *back = _tail;
		_tail = _tail->prev;
		if(_tail)
			_tail->next = _tail->next->next;
		else
			_head = 0;
			
		delete back;	
		_size--;
	}
	
//--- Reverse --------------------------------------------------------------
	void reverse()
	{
		llist *newhead = _tail;
		llist *esrever;
		for( ; newhead != NULL; newhead = newhead->next)
		{
			esrever = newhead->next;
			newhead->next = newhead->prev;
			newhead->prev = esrever;
		}
		llist *temp = _head;
		_head = _tail;
		_tail = temp;
	}
	
//--- Unique ---------------------------------------------------------------
	void unique()
	{
		for(llist *clean = _head; clean != NULL; clean = clean->next)
		{
			while(clean->next != NULL && clean->value == clean->next->value)
			{
				llist *data = clean->next;
				clean->next = data->next;
				if(data->next != NULL)
					data->next->prev = clean;
				else
					_tail = clean;
				
				delete data;
				_size--;
			}
		}
	}
	
//-- Class Friends ---------------------------------------------------------
	template<typename R>
	friend bool operator==(const List<R>& x, const List<R>& y);

	template<typename R>
	friend bool operator!=(const List<R>& x, const List<R>& y);

};

//--- Comparison Operators ------------------------------------------------
template<typename R>
bool operator==(const List<R>& x, const List<R>& y)
{
	auto aptr = x._head;
	auto bptr = y._head;
	// auto == const typename List<T>::llist *
	
	if(x.size() != y.size())
		return false;
	
	for( ; aptr != nullptr && bptr != nullptr; 
		   aptr=aptr->next, bptr=bptr->next)
	{
		if(aptr->value != bptr->value)
			return false;
	}
	return true;
}

template<typename R>
bool operator!=(const List<R>& x, const List<R>& y)
{
	auto aptr = x._head;
	auto bptr = y._head;
	
	for( ; aptr != nullptr && bptr != nullptr; 
		   aptr=aptr->next, bptr=bptr->next)
	{
		if(aptr->value != bptr->value)
			return true;
	}
	return false;
}

#endif // __EE231_List_h__