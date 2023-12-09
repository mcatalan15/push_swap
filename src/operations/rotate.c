/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:24:50 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:32:25 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Performs the "rotate" operation on the given stack.
Checks if the stack is empty, if the pointer is NULL,
or if the stack length is 1; in such cases, no rotation is performed
*/

static void	rotate(t_stack **a)
{
	t_stack	*last_node;
	int		len;

	len = stack_len(*a);
	if (a == NULL || *a == NULL || len == 1)
		return ;
	last_node = ft_find_last(*a);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/*
Performs the "rotate a" operation on the given stack
*/

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_printf("ra\n");
}

/*
Performs the "rotate b" operation on the given stack
*/

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_printf("rb\n");
}

/*
Performs the "rotate a" &"rotate b" operations on the given stack
*/

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_printf("rr\n");
}
