#include "stdafx.h"
#include "Transition.h"



Transition::Transition(const std::string& readSymbol, const std::string& currentState, const std::string& writeSymbol,
	const std::string& nextState,const std::string& command)
{
	this->readSymbol = readSymbol;
	this->currentState = currentState;
	this->writeSymbol = writeSymbol;
	this->nextState = nextState;
	this->command = command;
}
Transition::Transition(const Transition& other)
{
	this->readSymbol = other.readSymbol;
	this->currentState = other.currentState;
	this->writeSymbol = other.writeSymbol;
	this->nextState = other.nextState;
	this->command = other.command;
}

std::string Transition::get_readSymbol() const
{
	return this->readSymbol;
}
std::string Transition::get_writeSymbol() const
{
	return this->writeSymbol;
}
std::string Transition::get_command() const
{
	return this->command;
}
std::string Transition::get_currentState() const
{
	return this->currentState;
}
std::string Transition::get_nextState() const
{
	return this->nextState;
}
void Transition::set_nextState(const std::string& nextState)
{
	this->nextState = nextState;
}

std::ostream& operator<<(std::ostream& stream, Transition& transition)
{
	stream << transition.readSymbol
		<< "{" 
		<< transition.currentState 
		<< "}->"
		<< transition.writeSymbol
		<< "{" 
		<< transition.nextState 
		<< "}"
		<< transition.command
		<< std::endl;

	return stream;
}