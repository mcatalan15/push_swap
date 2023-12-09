/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:26:58 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/09 18:36:27 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Performs the "reverse rotate" operation on the given stack
*/

static void	ft_reverse_rotation(t_stack **a)
{
	t_stack	*last;
	int		len;

	len = stack_len(*a);
	if (*a == NULL || a == NULL || len == 1)
		return ;
	last = ft_find_last(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
}

/*
Performs the "reverse rotate a" operation on the given stack.
*/

void	rra(t_stack **a, bool checker)
{
	ft_reverse_rotation(a);
	if (!checker)
		ft_printf("rra\n");
}

/*
Performs the "reverse rotate b" operation on the given stack
*/
void	rrb(t_stack **b, bool checker)
{
	ft_reverse_rotation(b);
	if (!checker)
		ft_printf("rrb\n");
}
/*
Performs the "reverse rotate a" & "reverse rotate b" operation on the given stack
*/
void	rrr(t_stack **a, t_stack **b, bool checker)
{
	ft_reverse_rotation(a);
	ft_reverse_rotation(b);
	if (!checker)
		ft_printf("rrr\n");
}
