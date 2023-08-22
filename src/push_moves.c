/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:01 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/22 10:50:23 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_both(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*a != cheapest_n->target && *b != cheapest_n)
		rr(a, b, false);
	ft_position(*a);
	ft_position(*b);
}

static void	reverse_r_both(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*a != cheapest_n->target && *b != cheapest_n)
		rrr(a, b, false);
	ft_position(*a);
	ft_position(*b);
}

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
