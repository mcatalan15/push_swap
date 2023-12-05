/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:07 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/05 11:11:15 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	// char *num_str = "002147483647";
	// printf("%lld\n", ft_atol(num_str));

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		msg_err("Error\n");
	else if (argc == 2)
	{
		if (ft_syntax_2(argv[1]) == 1)
			msg_err("Error\n");
		else
			argv = ft_split(argv[1], ' ');
	}
	create_stack(&a, argv + 1, argc == 2);
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
