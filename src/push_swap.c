/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:07 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/07 12:31:54 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	main_2(t_stack *a, t_stack *b)
{
	if (!cheack_sort(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			ft_short_sort(&a);
		else
			push_swap(&a, &b);
	}
	ft_free_stack(&a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**my_argv;

	my_argv = &argv[1];
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !my_argv[0][0]))
		msg_err("Error\n");
	else if (argc == 2)
	{
		if (ft_syntax_2(my_argv[0]) == 1)
			msg_err("Error\n");
		else
			my_argv = ft_split(my_argv[0], ' ');
	}
	create_stack(&a, my_argv, argc == 2);
	main_2(a, b);
}
