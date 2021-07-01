/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:14:36 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/01 15:24:17 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void  *check_is_num(t_stack *stack, char **av, int index)
{
    void *num;
    int i;
    
    i = 0;
    if ((av[index][i] == '-' && ft_isdigit(av[index][i + 1])) || ft_isdigit(av[index][i]))
        i++;
    else
       quit_error(stack);
    while (av[index][i])
    {
        if (!ft_isdigit(av[index][i++]))
            quit_error(stack);
    }
    num = (void *)(intptr_t)ft_atoi_long(av[index]);
    //需要确认长度
    if ((long long)num > INT32_MAX ||  (long long)num < INT32_MIN)
		quit_error(stack);
    return (num);
}

static int  check_is_dup(t_list *a)
{
    t_list *tmp;
    t_list *tmp1;

    tmp = a;
    while (tmp && tmp->next)
    {
        tmp1 = tmp->next;
        while (tmp1)
        {
            if (tmp->content == tmp1->content)
               return(0);
            else
                tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    return (1);
 
}

t_list *num_to_stack(t_stack *stack, int ac, char **av)
{
    int i;
    void *num;
    void *n;
    t_list *stack_a;
     
    i = 1;
    stack_a = NULL;
    if (ac < 2)
       quit_success(stack);
    else if (ac == 2)
    {
        if (!check_is_num(stack, av, i))
             quit_error(stack);
        else
            quit_success(stack);
    }
    else
    {
        while (av[i])
        {
            num = check_is_num(stack, av, i);
            if (!num)
                 quit_error(stack);
            ++i;
        }
        i = 1;
        while (av[i])
        {
            n = check_is_num(stack, av, i);
            if (!num)
            {
                quit_error(stack);
            }
            ft_lstadd_back(&stack_a, ft_lstnew((void *)(intptr_t)n));
            i++;
        }
    }
    if (!check_is_dup(stack_a))
         quit_error(stack);
    return (stack_a);
}
