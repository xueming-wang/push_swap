/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:11:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/01 19:02:25 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"


typedef struct s_stack
{
    t_list *a;
    t_list *b;
    t_list *part_size;
    
}       t_stack;

typedef struct s_ope
{
    
}   t_ope;

void   ft_num_three(t_stack *stack);
void   ft_num_five(t_stack *stack);
void   ft_num_more(t_stack *stack);
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
t_list *num_to_stack(t_stack *statck, int ac, char **av);
void    exit_with_error_msg(void);
void    printstack(t_list *stack); // to delete after
void	option_v(t_stack *stacks);
void    quit_success(t_stack *stack);
void    quit_error(t_stack *stack);
int  find_mid(t_stack *stack, t_list *a_b, int size);
void    b_to_a(t_stack *stack);


#endif
