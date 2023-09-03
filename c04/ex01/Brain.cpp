#include "Brain.hpp"

Brain::Brain(){
    this->_ideas = new std::string[100];
    for (int i=0; i < 100; i++){
        _ideas[i] = "Default Brain idea";
    }
    std::cout << "Brain constuctor ran and filled with Default ideas" << std::endl;
}

Brain::Brain(std::string *ideas){
    this->_ideas = new std::string[100];
    for(int i=0; i < 100; i++){
        _ideas[i] = ideas[i];
    }
    std::cout << "Brain constuctor ran and filled" << std::endl;
}

Brain::Brain ( const Brain &copy ) {
	std::string	*ideas = copy.getIdeas();
	this->_ideas = new std::string[100];
	for ( int i = 0; i < 100; i++ )
		this->_ideas[i] = ideas[i];
	std::cout << "Copy constructor called, copied the ideas" << std::endl;
}

Brain &Brain::operator=(const Brain &assign) {
	for ( int i = 0; i < 100; i++ )
		_ideas[i] = assign._ideas[i];
	return (*this);
    std::cout << "Assignment operator called" << std::endl;
}

std::string	*Brain::getIdeas() const
{
	return (this->_ideas);
}

Brain::~Brain(){
    delete [] this->_ideas;
	std::cout << "Brain destructor called " << std::endl;
}


