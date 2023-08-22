/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:03 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/21 19:22:11 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				position;
	int				index;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//push_swap.c
void	push_swap(t_stack **a, t_stack **b);
void	create_stack(t_stack **a, char **argv, bool flag_argc_2);

//push_moves.c
t_stack	*ft_cheapest_return(t_stack *a);
void	finish_rotation(t_stack **a, t_stack *top_n, char sname);

// utils
// utils.c
int		ft_syntax(char *s);
void	ft_free_stack(t_stack **a);
void	ft_free(t_stack **a, char **argv, bool flag_argc_2);
int		ft_repetition(t_stack *a, int n);
//utils2.c
t_stack	*ft_find_last(t_stack *a);
void	ft_node_search(t_stack **a, int n);
int		stack_len(t_stack *a);
t_stack	*small_searcher(t_stack *a);

// sort
// sort.c
bool	cheack_sort(t_stack *stack);
// t_stack	*ft_highest(t_stack *a);
void	ft_short_sort(t_stack **a);
void	ft_five(t_stack **a, t_stack **b);

// push_swap.c
void	ft_position(t_stack *a);
void	ft_push_start(t_stack *a, t_stack *b);

// operations
// swap.c
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);
//rotate.c
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
//push.c
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);
//reverse_rotate.c
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

#endif