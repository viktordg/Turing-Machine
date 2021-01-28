#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include "Transition.h"
#include "Tape.h"
class Machine
{
private:
	std::vector<Tape> tapes;
	std::string currentState;
	std::map<std::string, std::vector<Transition>> map;
	Transition* findTransition(const char& readSymbol)
	{
		std::vector<Transition>& transitions = this->map[currentState];
		Transition* foundTransitions = nullptr;

		for (int i = 0; i < transitions.size(); i++) 
		{
			if (readSymbol == transitions[i].get_readSymbol()[0]) 
			{
				foundTransitions = &transitions[i];
			}
		}

		return foundTransitions;
	}
public:
	Machine();
	Machine(const Machine& other);

	void addTape(const Tape& tape);
	void addTransition(const Transition& transition);

	void move();
	void run();

	void loadMachine(std::string fileName);
	bool finishedSuccefully();

	std::vector<Transition>& get_transitions(const std::string);
	std::vector<std::string> get_states();
	std::string get_currentState();
	void set_tapes(std::vector<Tape> other);

	void compose(Machine& other);
	void branch(Machine& first, Machine& second);

	void printTapes();
};

