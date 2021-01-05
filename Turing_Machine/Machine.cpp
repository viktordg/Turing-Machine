#include "stdafx.h"
#include "Machine.h"


Machine::Machine() 
{

}

Machine::Machine(const Machine& other) 
{
	this->tape = other.tape;
}

void Machine::addTape(Tape& tape) 
{
	this->tape = &tape;
}

void Machine::run() 
{
	while (true)
	{
		char current = this->tape->read();
		if (current == '0')
		{
			this->tape->write('x');
			this->tape->moveRight();
			while (this->tape->read() == '0')
			{
				this->tape->moveRight();
			}
		}
		else if (current == '1')
		{
			this->tape->write('y');
			while (this->tape->read() != 'x')
			{
				this->tape->moveLeft();
			}
			this->tape->moveRight();
		}
		else if (current == ' ')
		{
			//reject 0 > 1
			break;
		}
		else if (current == 'y')
		{
			this->tape->moveRight();
			if (this->tape->read() == '1')
			{
				//reject 0 < 1
				break;
			}
			else if (this->tape->read() == ' ')
			{
				//accept ==
				break;
			}
		}
	}
}

void Machine::print() 
{
	std::cout << *this->tape << std::endl;
}
