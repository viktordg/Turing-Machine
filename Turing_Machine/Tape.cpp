#include "stdafx.h"
#include "Tape.h"

Tape::Tape(const std::string& input)
{
	std::copy(input.begin(), input.end(), std::back_inserter(this->tape));
	this->currentIndex = 0;
}
Tape::Tape(const Tape& other)
{
	this->tape = other.tape;
	this->currentIndex = other.currentIndex;
}

//char Tape::read() const
//{
//
//}
void Tape::write(char)
{

}
void Tape::moveLeft()
{

}
void Tape::moveRight()
{

}

int Tape::get_size() const
{
	return this->tape.size();
}

std::ostream& operator<<(std::ostream& out, Tape &outTape) 
{
	for (size_t i = 0; i < outTape.get_size(); i++)
	{
		out << outTape.tape[i];
	}
	return out;
}