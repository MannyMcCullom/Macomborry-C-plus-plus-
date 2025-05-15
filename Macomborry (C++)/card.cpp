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

string card::getLabel()
{
	return label;
}

string card::getOptionOne()
{
	return optionOne;
}

string card::getOptionTwo()
{
	return optionTwo;
}

card::card()
{

}