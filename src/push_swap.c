/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:07 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:05:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Here in main_2 is where we're going to have the second part of the main function.
	1-We are going to check if the stack a is sorted
	2-If the lenght of the stack is 2 just sa to swap the first to elements.
	3-If the lenght of the stack is 3 just the short sort.
	4-Execution of the main sort algorithm.
	5-Freeing stack A.
*/

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

/*
Here is the main function where we're going to have the second part of the main function.
	1-Copy argv to my_argv, and initialice variables.
	2-Checks if the argc not equal to 1 and if in case argc == 2 if argv[2] is not empty
	3-In case argc is 2 and not empty check the syntax and if the syntax its okay split argv
	4-From the splot or argv create the stack a with create stack_a
	5-calls to main_2 function
*/

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
