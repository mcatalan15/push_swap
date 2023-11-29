/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:55:03 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/29 12:40:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_syntax(char *s)
{
	// printf("ENTRA Syntax\n");
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	ft_free(t_stack **a, char **argv, bool flag_argc_2)
{
	int	i;

	ft_free_stack(a);
	if (flag_argc_2)
	{
		i = -1;
		if (argv == NULL || *argv == NULL)
			return ;
		while (argv[i])
			free(argv[i++]);
		free(argv - 1);
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_repetition(t_stack *a, int n)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

// int	ft_syntax2(char *s)
// {
// 	printf("ENTRA Syntax 2\n");
// 	printf("%s\n", s);
// 	// if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
// 	// 	return (1);
// 	// if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
// 	// 	return (1);
// 	// while (*++s)
// 	// {
// 	// 	if (!(*s >= '0' && *s <= '9'))
// 	// 		return (1);
// 	// }
// 	return (0);
// }

// int msg_err(char *str)
// {
// 	ft_printf("%s", str);
// 	exit(1);
// }

void	create_stack(t_stack **a, char **argv, bool flag_argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_syntax(argv[i]))
			ft_free(a, argv, flag_argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free(a, argv, flag_argc_2);
		if (ft_repetition(*a, (int)n))
			ft_free(a, argv, flag_argc_2);
		ft_node_search(a, (int)n);
		i++;
	}
	if (flag_argc_2 > 0)
	{
		i = -1;
		if (argv == NULL || *argv == NULL)
			return ;
		while (argv[i])
			free(argv[i++]);
		free(argv - 1);
	}
}
