#ifndef _DEBUG_H_
#define _DEBUG_H_

#include "iostream"

using namespace std;

class Debug{
private:
	// none
public:
	Debug();
	virtual void show() = 0; // print all data
};

#endif // _DEBUG_H_