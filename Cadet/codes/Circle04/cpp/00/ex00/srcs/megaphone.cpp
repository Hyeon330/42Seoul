# include <iostream>
# include <cctype>

int main(int ac, char **av) {
	int	i, j;

	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 0;
	while (++i < ac) {
		j = -1;
		while (av[i][++j])
			av[i][j] = std::toupper(av[i][j]);
		std::cout << av[i];
	}
	std::cout << std::endl;
    return 0;
}
