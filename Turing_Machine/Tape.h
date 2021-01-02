#pragma once
#include<vector>
#include<iostream>
class Tape
{
private:
	std::vector<char> tape;
	int currentIndex;
public:
	Tape(const std::string&);
	Tape(const Tape&);

	char read() const;
	void write(char);
	void moveLeft();
	void moveRight();

	int get_size() const;

	friend std::ostream& operator<<(std::ostream& out, Tape &tape);
};

