/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:57:40 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/22 10:42:46 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	sa(t_stack **a, bool checker)
{
	ft_swap(a);
	if (!checker)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool checker)
{
	ft_swap(b);
	if (!checker)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	ft_swap(a);
	ft_swap(b);
	if (!checker)
		ft_printf("ss\n");
}
