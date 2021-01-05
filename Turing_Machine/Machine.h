#pragma once
#include<iostream>
#include<string>
#include "Tape.h"
class Machine
{
private:
	Tape* tape;
public:
	Machine();
	Machine(const Machine& other);

	void addTape(Tape& tape);
	void run();
	void print();
};

