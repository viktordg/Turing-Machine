#include "stdafx.h"
#include<iostream>
#include<string.h>
#include "Tape.h"
#include "Machine.h"

int main()
{
	std::string tapeInput = "000111";
	std::cout << tapeInput.size() << std::endl;
	Tape tape(tapeInput);
	std::cout << tape << std::endl;
	Machine machine;
	machine.addTape(tape);
	machine.run();

    return 0;
}

