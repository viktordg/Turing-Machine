#pragma once
#include<iostream>
#include<string>
class Transition
{
private:
	std::string readSymbol;
	std::string writeSymbol;
	std::string command;
	std::string currentState;
	std::string nextState;
public:
	Transition(const std::string& readSymbol, const std::string& currentState, const std::string& writeSymbol,
		const std::string& nextState, const std::string& command);
	Transition(const Transition& other);

	std::string get_readSymbol() const;
	std::string get_writeSymbol() const;
	std::string get_command() const;
	std::string get_currentState() const;
	std::string get_nextState() const;
	void set_nextState(const std::string& nextState);

	friend std::ostream& operator<<(std::ostream& stream, Transition& transition);
};

