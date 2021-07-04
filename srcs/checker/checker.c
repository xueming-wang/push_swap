/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:08:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 15:36:35 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static void	show_stack_v(t_list *a, t_list *b)
{
	if (a == NULL && b == NULL)
		return ;
	if (a && b)
		printf("| %12d | %-12d |\n", (int)a->content, (int)b->content);
	else if (a)
		printf("| %12d | %-12c |\n", (int)a->content, ' ');
	else if (b)
		printf("| %12c | %-12d |\n", ' ', (int)b->content);
	if (a && b)
		show_stack_v(a->next, b->next);
	else if (a)
		show_stack_v(a->next, NULL);
	else if (b)
		show_stack_v(NULL, b->next);
}

void	option_v(t_stack *stacks)
{
	usleep(50000);
	printf("\033[2J\033[H");
	printf("-------------------------------\n");
	printf("| %12s | %-12s |\n", "Stack A", "Stack B");
	printf("-------------------------------\n");
	show_stack_v(stacks->a, stacks->b);
	printf("-------------------------------\n");
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}


int   ft_ope(t_stack *stack, char *line, int read)
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
int check_is_op(t_stack *stack, char *line, int read)
{
    if (!ft_ope(stack, line, read))
    {
        quit_error(stack);
    }
    return  (1);

}
void   read_and_check(t_stack *stack)
{
    char *line = NULL;
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
        // option_v(stack);
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