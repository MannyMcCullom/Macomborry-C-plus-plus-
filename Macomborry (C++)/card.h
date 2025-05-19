#ifndef H_card
#define H_card

#include <string>
#include <iostream>

using namespace std;

class card
{
public:
	void setLabel(string);
	void setOptionOne(string);
	void setOptionTwo(string);

	string getLabel() const;
	string getOptionOne() const;
	string getOptionTwo() const;
	
	card();

private:
	string label;
	string optionOne;
	string optionTwo;
};

#endif