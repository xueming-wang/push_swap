/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:11:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/23 16:56:31 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
    t_list *a;
    t_list *b;
    
}       t_stack;
void   ft_num_three(t_stack *stack);
void   ft_num_five(t_stack *stack);
int    ft_biggest(t_list *a);
int    ft_smallest(t_list *a);
void   ft_sa(t_stack *stack);
void   ft_sb(t_stack *stack);
void   ft_ss(t_stack *stack);
void   ft_pa(t_stack *stack);
void   ft_pb(t_stack *stack);
void   ft_ra(t_stack *stack);
void   ft_rb(t_stack *stack);
void   ft_rr(t_stack *stack);
void   ft_rra(t_stack *stack);
void   ft_rrb(t_stack *stack);
void   ft_rrr(t_stack *stack);

#endif
