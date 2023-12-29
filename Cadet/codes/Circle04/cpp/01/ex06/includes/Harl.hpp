#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
private:
	const static std::string	levels[];
	const static int			levelSize;

	void	(Harl::*harl[4])(void);
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl();
	~Harl();

	void	complain(std::string level);
};

#endif