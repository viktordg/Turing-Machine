#include "stdafx.h"
#include "Tape.h"

Tape::Tape(const std::string& input)
{
	std::copy(input.begin(), input.end(), std::back_inserter(this->tape));
	// F is used as blank space
	this->tape.push_back('F');
	this->current = 0;
}
Tape::Tape(const Tape& other)
{
	this->tape = other.tape;
	this->current = other.current;
}

void Tape::moveLeft()
{
	this->current--;
}
void Tape::moveRight()
{
	this->current++;
}
char Tape::read() const 
{
	return this->tape[this->current];
}
void Tape::write(char symbol) 
{
	this->tape[this->current] = symbol;
}
void Tape::moveToStart()
{
	while (this->current != 0)
	{
		this->moveLeft();
	}
}

int Tape::get_size() const
{
	return this->tape.size();
}
std::vector<char> Tape::get_tapeVector() const
{
	return this->tape;
}
char Tape::get_current() const
{
	return this->current;
}
std::string Tape::get_tapeString() const 
{
	std::string tapeString;
	for (size_t i = 0; i < this->tape.size(); i++)
	{
		tapeString += this->tape[i];
	}

	return tapeString;
}

std::ostream& operator<<(std::ostream& out, Tape &outTape) 
{
	for (size_t i = 0; i < outTape.get_size(); i++)
	{
		out << outTape.tape[i];
	}
	return out;
}