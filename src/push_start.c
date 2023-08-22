/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:41:41 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/21 18:49:38 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_position(t_stack *a)
{
	int	i;
	int	center;

	i = 0;
	if (a == NULL)
		return ;
	center = stack_len(a) / 2;
	while (a)
	{
		a->position = i;
		if (i <= center)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		i++;
	}
}

static void	ft_target(t_stack *a, t_stack *b)
{
	t_stack		*c_a;
	t_stack		*target;
	long		best;

	while (b)
	{
		best = LONG_MAX;
		c_a = a;
		while (c_a)
		{
			if (c_a->value > b->value && c_a->value < best)
			{
				best = c_a->value;
				target = c_a;
			}
			c_a = c_a->next;
		}
		if (LONG_MAX == best)
			b->target = small_searcher(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_price(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->price = b->position;
		if (!(b->above_median))
			b->price = b_len - (b->position);
		if (b->target->above_median)
			b->price += b->target->position;
		else
			b->price += a_len - (b->target->position);
		b = b->next;
	}
}

void	ft_cheapest(t_stack *b)
{
	long		best;
	t_stack		*best_n;

	if (b == NULL)
		return ;
	best = LONG_MAX;
	while (b)
	{
		if (b->price < best)
		{
			best = b->price;
			best_n = b;
		}
		b = b->next;
	}
	best_n->cheapest = true;
}

void	ft_push_start(t_stack *a, t_stack *b)
{
	ft_position(a);
	ft_position(b);
	ft_target(a, b);
	ft_price(a, b);
	ft_cheapest(b);
}
