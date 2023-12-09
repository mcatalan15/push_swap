/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:57:40 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:31:17 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Swaps the top two elements of a linked stack.
Checks if the stack is empty, if the pointer is NULL,
or if the stack length is 1; in such cases, no rotation is performed
*/

static void	ft_swap(t_stack **a)
{
	int	len;

	len = stack_len(*a);
	if (*a == NULL || a == NULL || len == 1)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
}

/*
Performs the "swap a" operation on the given stack
*/

void	sa(t_stack **a, bool checker)
{
	ft_swap(a);
	if (!checker)
		ft_printf("sa\n");
}

/*
Performs the "swap b" operation on the given stack
*/

void	sb(t_stack **b, bool checker)
{
	ft_swap(b);
	if (!checker)
		ft_printf("sb\n");
}

/*
Performs the "swap a" and "swap b" operations on the given stack
*/

void	ss(t_stack **a, t_stack **b, bool checker)
{
	ft_swap(a);
	ft_swap(b);
	if (!checker)
		ft_printf("ss\n");
}
