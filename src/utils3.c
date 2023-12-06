/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:49:34 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/06 13:21:10 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	len_num(char *str)
{
	int	i;
	int	flag;
	int	count;

	flag = 0;
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] > '0' && str[i] <= '9')
			flag = 1;
		if (str[i] >= '0' && str[i] <= '9' && flag == 1)
			count++;
	}
	return (count);
}

int	ft_syntax_2(char *s)
{
	int				i;
	long long int	num;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
	}
	num = ft_atol(s);
	if (num > INT_MAX || num < INT_MIN || len_num(s) > 10)
		return (1);
	return (0);
}

int	msg_err(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}
