/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:46:58 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:52:12 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Checks if a given linked stack is sorted in ascending order
*/

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

/*
Finds and returns the node with the highest value in the given stack
	1-Initializes "h" to "INT_MIN" and "highest_node" to "NULL"
	2-If a node with a higher value is encountered. updates "h" and
		"higher_value"
	3-Returns the pointher to the node with highest value.
*/

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

/*
Performs the "reverse rotate" operation on the given stack
	1-Calls "ft_highest" to find the highest node in the stack.
	2-If the highest node is the top of the stack, rotates the
		stack in ascending order (ra)
	3-If the highest node is the second element, reverse rotates
		the stack in ascending order (rra)
	4-Compares the values of the top two elements and swaps them
		if necessary (sa)
*/

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

/*
Handles a specific case when the length of stack 'a' is 5
	1-Moves elements from stack 'a' to stack 'b' until
		there are only three elements left in stack 'a'
	2-Calls ft_push_start to push the element with the
		highest value to the top of stack 'b'
	3-Calls finish_rotation to rotate stack 'a' to
		position the smallest element correctly
	4-Calls pb to push the smallest element from
		stack 'a' to stack 'b'.
*/

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
