/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:55:03 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:24:41 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_syntax(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
			|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f'))
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
	return (0);
}

/*
Frees the mem of the given stack
*/

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

/*
Free mem of the stack with ft_free_stack and command line arguments.
Also exits with error msg.
*/

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

/*
Check if an int value exist in the stack.
*/

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

/*
	1-Initialize the stack_a
	2-Check the syntax for every paramenter given. and frees the mem in case
		the syntax is incorrect.
	3-Convert the str to ft_atol and check its not bigger than an int
	4-Checks if there're repetitions with ft_repetitions and frees mem in chase
		there're
	5-Add the num into the stack as a node with ft_node_search.
	6-If bool flag_argc means argc==2 and cleans the mem.
*/

void	create_stack(t_stack **a, char **argv, bool flag_argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_syntax_2(argv[i]))
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
		if (argv == NULL)
			return ;
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}
