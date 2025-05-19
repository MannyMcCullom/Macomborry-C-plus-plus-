#include "card.h"

void card::setLabel(string newLabel)
{
	label = newLabel;
}

void card::setOptionOne(string newOptionOne)
{
	optionOne = newOptionOne;
}

void card::setOptionTwo(string newOptionTwo)
{
	optionTwo = newOptionTwo;
}

string card::getLabel() const
{
	return label;
}

string card::getOptionOne() const
{
	return optionOne;
}

string card::getOptionTwo() const
{
	return optionTwo;
}

card::card()
{

}