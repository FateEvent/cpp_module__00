#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class Brain
{
public:
	Brain( void );
	Brain( const Brain &other );
	~Brain( void );
	Brain &			operator = ( const Brain &other );
	std::string		*getIdeas( void );
	void			displayIdeas( void ) const;

protected:
	std::string		_ideas[100];
};

#endif
