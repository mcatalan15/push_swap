/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:24:50 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/22 10:41:26 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_printf("rr\n");
}
