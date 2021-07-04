/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:08:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 16:05:49 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int check_is_sort(t_stack *stack, int size)
{
    t_list *tmp;
    
    tmp = stack->a;
    if (ft_lstsize(stack->a) != size)
        return (0);
    while (tmp->next)
    {
        if ((int)tmp->content < (int)tmp->next->content)
        {
            tmp = tmp->next;
        }
        else
            return (0);
    }
     return (1);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}


static int   ft_ope(t_stack *stack, char *line, int read)
{   
    
        if (!ft_strcmp(line, "sa"))
            ft_sa(stack, 0);
        else if (!ft_strcmp(line, "sb"))
            ft_sb(stack, 0);
        else if (!ft_strcmp(line, "ss"))
            ft_ss(stack, 0);
        else if (!ft_strcmp(line, "pa"))
            ft_pa(stack, 0);
        else if (!ft_strcmp(line, "pb"))
            ft_pb(stack, 0);
        else if (!ft_strcmp(line, "ra"))
            ft_ra(stack, 0);
        else if (!ft_strcmp(line, "rb"))
            ft_rb(stack, 0);
        else if (!ft_strcmp(line, "rr"))
            ft_rr(stack, 0);
        else if (!ft_strcmp(line, "rra"))
            ft_rra(stack, 0);
        else if (!ft_strcmp(line, "rrb"))
            ft_rrb(stack, 0);
        else if (!ft_strcmp(line, "rrr"))
            ft_rrr(stack, 0);
        else if (read == 0)
            return (1);
        else
            return (0);
   
    return (1);
    
}
static int check_is_op(t_stack *stack, char *line, int read)
{
    if (!ft_ope(stack, line, read))
    {
        quit_error(stack);
    }
    return  (1);

}
void   read_and_check(t_stack *stack)
{
    char *line;
    int read;
    int i;
    int size;

    size = ft_lstsize(stack->a);
    read = 1;
    i = 0;
    
    while (read > 0)
    {
        read = get_next_line(STDIN_FILENO, &line);
        if (!check_is_op(stack, line, read))
        {
            free(line);
            quit_error(stack);
        }
        
        free(line);
    }
    if(check_is_sort(stack, size))
    {
        ft_putstr("OK\n");
        quit_success(stack);
    }
    else 
    {
        ft_putstr("KO\n");
        quit_success(stack);
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