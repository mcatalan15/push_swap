/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:49:34 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:12:05 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
With a given string, counts the num of charaters the string has
*/

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

/*
This function check if the given string pass the syntax filter for the push_swap in the argc==2 case
	1-Delete spaces and checks there's no other char thats not a num
	2- Use ft_atol to convert the num in string format to long long int and check if the num given
		is bigger than INT_MAX or INT_MIN. Also if the num of digits is bigger than 10 with len_num
		function
*/

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

/*
Function used to ouput a str given on the standar error output with exit 1;
*/

int	msg_err(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}
