#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{
private:
    std::string *_ideas;
public:
    Brain();
    Brain(std::string *var);
    Brain(const Brain &var);
    ~Brain();
    Brain &operator=(const Brain &assign);
    std::string *getIdeas() const;

};

#endif