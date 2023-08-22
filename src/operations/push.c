/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:01:34 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/22 10:34:12 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	ft_push(a, b);
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	ft_push(b, a);
	if (!checker)
		ft_printf("pb\n");
}
