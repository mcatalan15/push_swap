/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:26:19 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/22 10:48:42 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_find_last(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_node_search(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = n;
	if (NULL == *a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack *a)
{
	int	c;

	if (NULL == a)
		return (0);
	c = 0;
	while (a)
	{
		++c;
		a = a->next;
	}
	return (c);
}

t_stack	*small_searcher(t_stack *a)
{
	long		small;
	t_stack		*small_node;

	if (a == NULL)
		return (NULL);
	small = LONG_MAX;
	while (a)
	{
		if (a->value < small)
		{
			small = a->value;
			small_node = a;
		}
		a = a->next;
	}
	return (small_node);
}
