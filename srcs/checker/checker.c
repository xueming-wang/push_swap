/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:08:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/01 20:02:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int check_is_sort(t_list *a)
{
    t_list *tmp;
    
    tmp = a;
    while (tmp->next)
    {
        if (tmp->content < tmp->next->content)
            tmp = tmp->next;
        else
            return (0);
    }
     return (1);
}

void   read_and_check(t_stack *stack)
{
    char *line;
    int read;

    read = 1;
    while (read > 0)
    {
        read = get_next_line(1, &line);
        if (!"sa" && !"sb" && !"ss" && !"pa" && !"pb" && !"ra" && !"rb" && !"rr" && !"rra" && !"rrb" && !"rrr")
            quit_error(stack);
        free(line);
    }
    
     if(check_is_sort(stack->a))
        {
            quit_success(stack);
            ft_putstr("OK");
        }
        else 
        {
            quit_error(stack);
            ft_putstr("KO");
        }
}

    
int main(int ac, char**av)
{
    t_stack *stack;
    stack = NULL;
    
    stack->a = num_to_stack(stack, ac, av);
    if (!stack)
        quit_error(stack);
    if (stack->a)
    {
        read_and_check(stack);
    }
    return (0);
}