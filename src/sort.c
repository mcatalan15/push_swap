/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:46:58 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/18 11:39:46 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	cheack_sort(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*ft_highest(t_stack *a)
{
	int		h;
	t_stack	*highes_node;

	if (a == NULL)
		return (NULL);
	h = INT_MIN;
	while (a)
	{
		if (a->value > h)
		{
			h = a->value;
			highes_node = a;
		}
		a = a->next;
	}
	return (highes_node);
}

void	ft_short_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = ft_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)-> value > (*a)->next->value)
		sa(a, false);
}

void	ft_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		ft_push_start(*a, *b);
		finish_rotation(a, small_searcher(*a), 'a');
		pb(b, a, false);
	}
}

t_stack	*ft_cheapest_return(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}
