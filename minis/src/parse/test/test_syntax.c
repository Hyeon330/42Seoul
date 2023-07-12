#include "test.h"

int	check_redirection(char *str)
{
	enum e_redir_type	redir_type;
	int					flag;

	flag = 1;

	if (ft_strncmp(str, "<" , ft_strlen(str)) == 0)
		redir_type = IN_REDIR;
	else if (ft_strncmp(str, ">" , ft_strlen(str)) == 0)
		redir_type = OUT_REDIR;
	else if (ft_strncmp(str, "<<" , ft_strlen(str)) == 0 || \
	ft_strncmp(str, ">>" , ft_strlen(str)) == 0)
		redir_type = APPEND;
	else
		flag = -1;
	return (flag);
}

void	syntax_redirection(char **splited, int i)
{
	if (splited[i] != NULL && check_redirection(splited[i]) == -1)
		syntax_word(splited, ++i);
	else
		error("no word after redirection");
}

void	syntax_word(char **splited, int i)
{
	if (splited[i] != NULL)
		return ;
	else if (check_redirection(splited[i]) == 1)
		syntax_redirection(splited, ++i);
	else
		syntax_word(splited, ++i);
}

void	syntax_check(char **splited, int order)
{
	int	i;

	i = 0;
	if (order != 0 && check_redirection(splited[0]) != -1)
			error("redirection after pipe");//pipe 뒤에 redirection이 오는 것 방지
	if (check_redirection(splited[i]) == 1)
		syntax_redirection(splited, ++i);
	else
		syntax_word(splited, ++i);
}
/*
int main()
{
	char	*str = "< a << b infile 'ls > <<-al'";
	char	**splited;

	splited = split_token_main(str);
	syntax_check(splited, 0);
	printf ("yes\n");
}*/
//gcc test_syntax.c test_split_token.c test_count_token.c test_utils.c

/*
< a << b infile ls -al
<a<<b infile ls -al
< a << b infile 'ls > -al'
< a << b infile 'ls > <<-al'
<<< a b
<>> a b
>>a b
>><>>
*/