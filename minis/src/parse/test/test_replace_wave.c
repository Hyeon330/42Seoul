#include "test.h"

int main()
{
	char	*str = "hello ~this is wave test";
	char	*home_path = "/Users/eoh";
	int		i = 6;
	char	*temp1;
	char	*temp2;
	char	*result;
	char	*old_result;

	temp1 = ft_substr(str, 0, i); //물결전까지 자름
	temp2 = ft_substr(str, i + 1, ft_strlen(str) - 1);
	result = ft_strjoin(temp1, home_path);
	old_result = result;
	result = ft_strjoin(result, temp2);
	free(old_result);
	free(temp1);
	free(temp2);
	printf("%s\n", result);
}
//gcc test_replace_wave.c test_utils.c