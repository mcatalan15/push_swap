/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:01 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/10 16:53:10 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Reverse both stacks until cheapest elements are on the position
*/

static void	r_both(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*a != cheapest_n->target && *b != cheapest_n)
		rr(a, b, false);
	ft_position(*a);
	ft_position(*b);
}

/*
Reverse rotate both stacks until cheapest elements are on the position
*/

static void	reverse_r_both(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*a != cheapest_n->target && *b != cheapest_n)
		rrr(a, b, false);
	ft_position(*a);
	ft_position(*b);
}

/*
Rotates  or reverse stack 'A' until the top element of the stack is at the specified target position
*/

void	finish_rotation(t_stack **a, t_stack *top_n, char sname)
{
	while (*a != top_n)
	{
		if (sname == 'a')
		{
			if (top_n->above_median)
				ra(a, false);
			else
				rra(a, false);
		}
		else if (sname == 'b')
		{
			if (top_n->above_median)
				rb(a, false);
			else
				rrb(a, false);
		}
	}
}

/*
Performs a moves based on the cheapest element in stack 'B'
	1-Check if the cheapest is above the median and rotate both stacks
	2-Uf the cheapest and the target is below the median reverse rotate both stacks
	3-Finish rotation to perform additional rotations for the cheapest element and targets.
	4-Push cheapest element from stack 'B' to 'A'
*/

static void	ft_moves(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_n;

	cheapest_n = ft_cheapest_return(*b);
	if (cheapest_n->above_median && cheapest_n->target->above_median)
		r_both(a, b, cheapest_n);
	else if (!(cheapest_n->above_median) && !(cheapest_n->target->above_median))
		reverse_r_both(a, b, cheapest_n);
	finish_rotation(b, cheapest_n, 'b');
	finish_rotation(a, cheapest_n->target, 'a');
	pa(a, b, false);
}

/*
Implements the main algorithm for sorting the stack 'a' using the push_swap approach.
	1-Check the lenght of stack A
	2-If lenght 5 calls ft_five.
	3-Otherwise continues with the default case.
	4-Moves elements from stack 'A' to stack 'B' until there're 3 elements
		left in stack 'A'
	5-Calls ft_short_sort to sort the remaining elements of stack 'A'.
	6-Pushes elements back from stack 'B to stack 'A'
	7-Calls ft_moves to perform additional moves and optimizations
	8-Calls ft_positions to adjust the positions of elements in stack 'A'.
	9-Search the smallest element and determines its positions.
	10-Rotates stack 'A' to position the smallest element correctly.
*/

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		a_len;

	a_len = stack_len(*a);
	if (a_len == 5)
		ft_five(a, b);
	else
	{
		while (a_len-- > 3)
			pb(b, a, false);
	}
	ft_short_sort(a);
	while (*b)
	{
		ft_push_start(*a, *b);
		ft_moves(a, b);
	}
	ft_position(*a);
	smallest = small_searcher(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
