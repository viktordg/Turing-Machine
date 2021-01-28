#include "stdafx.h"
#include "Machine.h"
#include<fstream>


Machine::Machine() 
{
	this->currentState = "q0";
}
Machine::Machine(const Machine& other) 
{
	this->currentState = other.currentState;
	this->tapes = other.tapes;
}
void Machine::addTape(const Tape& tape)
{
	tapes.push_back(tape);
}
void Machine::addTransition(const Transition& transition)
{
	map[transition.get_currentState()].push_back(transition);
}
void Machine::move()
{
	Transition* next = findTransition(tapes[0].read());

	if (next == nullptr) 
	{
		currentState = "reject";
		return;
	}

	std::cout << *next;
	currentState = next->get_nextState();

	for (int i = 0; i < tapes.size(); i++) 
	{
		if (next->get_writeSymbol().length() != 0) 
		{
			tapes[i].write(next->get_writeSymbol()[i]);
		}

		if (next->get_command()[i] == 'R')
		{
			tapes[i].moveRight();
			break;
		}
		else if (next->get_command()[i] == 'L')
		{
			tapes[i].moveLeft();
			break;
		}
		else
		{
			break;
		}
	}
}
void Machine::run()
{
	std::string tapeString = tapes[0].get_tapeString();

	while (currentState != "reject" && currentState != "accept") 
	{
		move();
	}
}
void Machine::loadMachine(std::string fileName) 
{
	std::ifstream inputFile(fileName);
	if (inputFile.is_open()) 
	{
		std::string numberOfTapes;
		getline(inputFile, numberOfTapes);

		for (int i = 0; i < std::stoi(numberOfTapes); i++) 
		{
			std::string tapeLine;
			getline(inputFile, tapeLine);
			Tape tape = Tape(tapeLine);
			addTape(tape);
		}

		if (this->tapes.size() == 1)
		{
			std::string line;
			while (getline(inputFile, line))
			{
				std::string readSymbol;
				std::string currentState;
				std::string writeSymbol;
				std::string nextState;
				std::string command;

				readSymbol += line[0];
				currentState += line[2];
				currentState += line[3];
				writeSymbol += line[7];
				if (line[9] == 'a')
				{
					nextState = "accept";
				}
				else
				{
					nextState += line[9];
					nextState += line[10];
				}
				command += line[line.length() - 1];


				Transition transition = Transition(readSymbol, currentState, writeSymbol, nextState, command);
				this->addTransition(transition);
			}
		}
		else
		{
			std::string line;
			while (getline(inputFile, line))
			{
				std::string readSymbol;
				std::string currentState;
				std::string writeSymbol;
				std::string nextState;
				std::string command;

				readSymbol += line[0];
				readSymbol += line[1];
				readSymbol += line[2];

				currentState += line[4];
				currentState += line[5];

				writeSymbol += line[9];
				writeSymbol += line[10];
				writeSymbol += line[11];

				if (line[13] == 'a')
				{
					nextState = "accept";
				}
				else
				{
					nextState += line[13];
					nextState += line[14];
				}
				command += line[line.length() - 3];
				command += line[line.length() - 2];
				command += line[line.length() - 1];


				Transition transition = Transition(readSymbol, currentState, writeSymbol, nextState, command);
				this->addTransition(transition);
			}
		}

		inputFile.close();
	}
}
bool Machine::finishedSuccefully()
{
	return this->currentState == "accept";
}
std::vector<Transition>& Machine::get_transitions(const std::string state)
{
	return this->map[state];
}
std::vector<std::string> Machine::get_states()
{
	std::vector<std::string> states;

	for (std::map<std::string, std::vector<Transition>>::iterator iterator = map.begin(); iterator != map.end(); iterator++)
	{
		states.push_back(iterator->first);
	}

	return states;
}
std::string Machine::get_currentState()
{
	return this->currentState;
}
void Machine::set_tapes(std::vector<Tape> other)
{
	this->tapes = other;
}
void Machine::compose(Machine& other)
{
	std::vector<std::string> otherStates = other.get_states();

	for (size_t i = 0; i < this->get_states().size(); i++) 
	{
		std::vector<Transition>& transitions = map[this->get_states()[i]];

		for (size_t j = 0; j < transitions.size(); j++)
		{
			Transition& transition = transitions[j];

    		if (transition.get_nextState() == "accept")
			{
				transition.set_nextState(other.get_currentState());
			}
		}
	}

	for (size_t i = 0; i < otherStates.size(); i++)
	{
		std::vector<Transition>& otherTransitions = other.get_transitions(otherStates[i]);

		for (size_t j = 0; j < otherTransitions.size(); j++)
		{
			map[otherStates[i]].push_back(otherTransitions[j]);
		}
	}
}
void Machine::branch(Machine& first, Machine& second)
{
	std::vector<Tape> tapes = this->tapes;
	this->run();

	if (this->finishedSuccefully())
	{
		first.set_tapes(tapes);
		first.run();
	}
	else
	{
		second.set_tapes(tapes);
		second.run();
	}
}
void Machine::printTapes() 
{
	for (int i = 0; i < tapes.size(); i++) 
	{
		std::cout << tapes[i] << std::endl;
	}
}