#include "test.h"

int main()
{
	char	*str = "hello this is $? exit code test";
	int		i = 14;
	char	*exit_code;
	char	*temp1;
	char	*temp2;
	char	*result;
	char	*old_result;
	
	exit_code = ft_itoa(123);
	temp1 = ft_substr(str, 0, i);
	temp2 = ft_substr(str, i + 2, ft_strlen(str) - 1);
	result = ft_strjoin(temp1, exit_code);
	old_result = result;
	result = ft_strjoin(result, temp2);
	free(old_result);
	free(temp1);
	free(temp2);
	//free(str);
	printf("%s\n", result);
}