/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:08:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/03 19:52:43 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


static int check_is_sort(t_list *a)
{
    t_list *tmp;
    
    tmp = a;
    while (tmp->next)
    {
        if ((int)tmp->content < (int)tmp->next->content)
            tmp = tmp->next;
        else
            return (0);
    }
     return (1);
}

int check_is_op(char *line)
{
    const char *op[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr",  NULL};
    int i;

    i = 0;
    while (op[i])
    {
        if (!ft_strncmp(op[i], line, 2) && line[2] == '\0')
            return (1);   
        else
            ++i;
    }
    return (0);
}

void   ft_ope(t_stack *stack, char *line)
{   
    if (ft_strncmp(line, "sa", 2) == 0)
        ft_sa(stack, 0);
    else if (ft_strncmp(line, "sb", 2) == 0)
        ft_sb(stack, 0);
    else if (ft_strncmp(line, "ss", 2) == 0)
        ft_ss(stack, 0);
    else if (ft_strncmp(line, "pa", 2) == 0)
        ft_pa(stack, 0);
    else if (ft_strncmp(line, "pb", 2) == 0)
        ft_pb(stack, 0);
    else if (ft_strncmp(line, "ra", 2) == 0)
        ft_ra(stack, 0);
    else if (ft_strncmp(line, "rb", 2) == 0)
        ft_rb(stack, 0);
    else if (ft_strncmp(line, "rr", 2) == 0)
        ft_rr(stack, 0);
    else if (ft_strncmp(line, "rra", 3) == 0)
        ft_rra(stack, 0);
    else if (ft_strncmp(line, "rrb", 3) == 0)
        ft_rrb(stack, 0);
    else if (ft_strncmp(line, "rrr", 3) == 0)
        ft_rrr(stack, 0);   
}

void   read_and_check(t_stack *stack)
{
    char *line;
    int read;
    int i;

    read = 1;
    i = 0;
    
    while ((read = get_next_line(STDIN_FILENO, &line)) > 0)
    {
            if (!check_is_op(line))
            {
                free(line);
                quit_error(stack);
            }
            else
              ft_ope(stack, line);
    }
    if (stack->a)
    {
        if(check_is_sort(stack->a) && (!stack->b))
        {
            ft_putstr("OK\n");
            free(line);
            quit_success(stack);
            
        }
        else 
        {
            ft_putstr("KO\n");
            free (line);
            quit_success(stack);
        }
    }
     free(line);
}
    
int main(int ac, char**av)
{


    t_stack *stack;
 
    stack = malloc(sizeof(t_stack));
    if (!stack)
        quit_error(NULL);
    ft_bzero(stack, sizeof(t_stack));
    stack->a = num_to_stack(stack, ac, av);
    read_and_check(stack);
    return (0);
}