#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#include "Queue.h"
typedef Queue<std::string> StringQueue;
typedef Queue<int> IntQueue;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#include <queue>
typedef std::queue<std::string> StringQueue;
typedef std::queue<int> IntQueue;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
//--- Delcare Lists -----------------------------------------------------------------
	StringList sList_1, sList_2;
	IntList iList_1, iList_2;
//--- Test List Funtions ------------------------------------------------------------
	std::cout << "Testing List Funtions: \n";
	sList_1.push_front("one");
	sList_1.push_back("two");
	
	Assert(sList_1.front() == "one", "front of StringList_1 == one");
	Assert(sList_1.back() == "two", "back of StringList_1 == two");
	Assert(sList_1.size() == 2, "size of StringList_1 == 2");
	Assert(sList_2.empty() == true, "StringList_2 is empty");
	
	iList_1.push_back(1);
	iList_1.push_back(2);
	iList_1.push_back(3);
	std::cout << "Pop Front of IntList_1 \n";
	iList_1.pop_front();
	std::cout << "Pop Back of IntList_1 \n";
	iList_1.pop_back();
	Assert(iList_1.front() == 2, "front of IntList_1 == 2");
	iList_2 = iList_1;
	Assert(iList_1 == iList_2 , "IntList_2 = IntList_1");
	std::cout << "\n";
	
//--- Test Stack --------------------------------------------------------------------
	std::cout << "Testing Stack \n";
	StringStack sStack_1, sStack_2;
	IntStack iStack_1, iStack_2;
	
	sStack_1.push("Red");
	sStack_1.push("Blue");
	Assert(sStack_1.top() == "Blue", "Blue is at top of StringStack_1"); 
	std::cout << "StringStack_2 = StringStack_1 \n";
	sStack_2 = sStack_1;
	Assert(sStack_2.top() == "Blue", "Blue is at top of StringStack_2"); 
	Assert(sStack_2 == sStack_1, "StringStack_2 == StringStack_1"); 
	sStack_2.pop();
	Assert(sStack_2 != sStack_1, "StringStack_2 != StringStack_1");
	sStack_1.push("Green");
	sStack_2.pop();
	Assert(sStack_2.empty() == true, "StringStack_2 is empty");
	Assert(sStack_1.empty() == false, "StringStack_1 is not empty");
	
	iStack_1.push(2);
	iStack_1.push(1);
	Assert(iStack_1.top() == 1, "1 is at top of IntStack_1");
	Assert(iStack_2.empty() == true, "IntStack_2 is empty");
	Assert(iStack_1.empty() == false, "IntStack_1 is not empty");
	iStack_2.push(33);
	iStack_2.push(1);
	Assert(iStack_2 != iStack_1, "IntStack_2 != IntStack_1");
	iStack_2.push(4);
	iStack_2.push(12);
	Assert(iStack_2.size() == 4, "IntStack_2 size = 4");
	iStack_1 = iStack_2;
	Assert(iStack_2 == iStack_1, "IntStack_2 == IntStack_1");
	//Assert(iStack_2 != sStack_1, "IntStack_2 != StringStack_1");
	//iStack_2.push("string");
	//sStack_1.push(10);
	std::cout << "\n";
	
//--- Test Queue --------------------------------------------------------------------
	std::cout << "Testing Queue \n";
	StringQueue sQ_1, sQ_2;
	IntQueue iQ_1, iQ_2;
	
	sQ_1.push("A");
	sQ_1.push("B");
	sQ_1.push("C");
	sQ_1.push("D");
	
	Assert(sQ_1.front() == "A", "Frist in StringQueue_1 = A");
	Assert(sQ_1.back() == "D", "Last in StringQueue_1 = D");
	Assert(sQ_1.size() == 4, "Size of StringQueue_1 = 4");
	Assert(sQ_2.size() == 0, "Size of StringQueue_2 = 0");
	
	sQ_2 = sQ_1;
	Assert(sQ_1 == sQ_2, "StringQueue_1 == StringQueue_2");
	
	sQ_2.push("F");
	Assert(sQ_2.back() == "F", "Last in StringQueue_2 is F");
	sQ_1.push("f");
	Assert(sQ_1 != sQ_2, "StringQueue_1 != StringQueue_2");
	
	iQ_1.push(22);
	iQ_1.push(16);
	iQ_1.push(8);
	iQ_1.push(2);
	
	Assert(iQ_1.front() == 22, "Frist in IntQueue_1 is 22");
	iQ_1.pop();
	Assert(iQ_1.front() == 16, "Next in IntQueue_1 is 16");
	iQ_1.pop();
	Assert(iQ_1.front() == 8, "Next in IntQueue_1 is 8");
	iQ_1.pop();
	Assert(iQ_1.front() == 2, "Next in IntQueue_1 is 2");
	iQ_1.pop();
	Assert(iQ_1.empty() == true, "IntQueue_1 is Empty");
	iQ_2.push(0123456);
	Assert(iQ_2.size() == 1, "Size of IntQueue_2 is one");
	std::cout<< "\n";
//--- End of Testing ------------------------------------------------------------	
	return 0;
}


