/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:53:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/12 14:55:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fibo(int *dp, int index, int i)
{
	if (i <= index)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		fibo(dp, index, i + 1);
	}
}

int	ft_fibonacci(int index)
{
	int	dp[1000];

	dp[0] = 0;
	dp[1] = 1;
	if (index < 0)
		return (-1);
	fibo(dp, index, 2);
	return (dp[index]);
}
