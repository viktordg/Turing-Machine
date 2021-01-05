#pragma once
#include<vector>
#include<iostream>
class Tape
{
private:
	std::vector<char> tape;
	int current;
public:
	Tape(const std::string& input);
	Tape(const Tape& current);

	char read() const;
	void write(char symbol);
	void moveLeft();
	void moveRight();

	int get_size() const;
	std::vector<char> get_tapeVector() const;
	char get_current() const;

	friend std::ostream& operator<<(std::ostream& out, Tape &tape);
};

