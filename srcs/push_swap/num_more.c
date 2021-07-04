/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:42:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/03 21:17:18 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// static void	show_stack_v(t_list *a, t_list *b)
// {
// 	if (a == NULL && b == NULL)
// 		return ;
// 	if (a && b)
// 		printf("| %12d | %-12d |\n", (int)a->content, (int)b->content);
// 	else if (a)
// 		printf("| %12d | %-12c |\n", (int)a->content, ' ');
// 	else if (b)
// 		printf("| %12c | %-12d |\n", ' ', (int)b->content);
// 	if (a && b)
// 		show_stack_v(a->next, b->next);
// 	else if (a)
// 		show_stack_v(a->next, NULL);
// 	else if (b)
// 		show_stack_v(NULL, b->next);
// }

// void	option_v(t_stack *stacks)
// {
// 	usleep(50000);
// 	printf("\033[2J\033[H");
// 	printf("-------------------------------\n");
// 	printf("| %12s | %-12s |\n", "Stack A", "Stack B");
// 	printf("-------------------------------\n");
// 	show_stack_v(stacks->a, stacks->b);
// 	printf("-------------------------------\n");
// }




//左面切一次，小数放右边
static void   action_sepa(t_stack *stack, int size)
{
   
    int mid;
    int i = 0;
    
    mid = find_mid(stack, stack->a, size);
    size = ft_lstsize(stack->a);
    while (i < size / 2)
    {
        if ((int)stack->a->content < mid)
        {
            ft_pb(stack, 1);
            i++;
        }
        else
            ft_ra(stack, 1);
    } 
    
}


//右边一直切 大的放回去切到没有数字，保存每次切的size 成为list链表
static void    action_b_list(t_stack *stack)
{
    int count;
    int mid;
    int i;
    int size;
    
    while (stack->b)
    {
        count = 0;
        mid = find_mid(stack, stack->b, ft_lstsize(stack->b));
       
        size = ft_lstsize(stack->b);
        i = size;
        while (i > size / 2)
        {
            if ((int)stack->b->content >= mid)
            {
                ft_pa(stack, 1);
                i--;
                count++;
            }
            else
                ft_rb(stack, 1);
        }
        ft_lstadd_front(&stack->part_size, ft_lstnew((void *)(intptr_t)count));
    }
     //ok
}

//处理一段 ,找中间数切一段小的放右边， 大的放最下面， 大的放回最上边，右边按b to a处理 ，最大的数放过右边pb 最后再b to a
 static void    action_one_part(t_list *part_size, t_stack *stack)
{
    int i;
    int j;
    int mid;
    
    i = 0;
    j = 0;
    
    mid = find_mid(stack, stack->a, (int)part_size->content);
    while (i < (int)part_size->content)
    {
        if ((int)stack->a->content >= mid)
        {
            ft_ra(stack, 1);
            j++;
        }
        else
            ft_pb(stack, 1);
        i++;
    }
    i = 0;
    while (i < j)
    {
        ft_rra(stack, 1);
        i++;
    }
    b_to_a(stack);
    while (j--)
        ft_pb(stack, 1);
    b_to_a(stack);
}    
//运行所有的 段落
static void    sort_all(t_stack *stack)
{
    int i;
    t_list *tmp;
    
    i = 0;
    stack->part_size = NULL; //ok
   
   action_b_list(stack);
     
    tmp = stack->part_size;
    while (tmp)
    {
        if ((int)tmp->content == 1)
        {
            ft_ra(stack, 1);
        }
        else if ((int)tmp->content == 2)
        {
            if ((int)stack->a->content > (int)stack->a->next->content)
                ft_sa(stack, 1);
            ft_ra(stack, 1);
            ft_ra(stack, 1);
            
        }
        else 
            action_one_part(tmp, stack);
        tmp = tmp->next;
       
    }
}



 void      ft_num_more(t_stack *stack)
{
    int size;
    int size2 = 0;
    int i = 0;
    
    size = ft_lstsize(stack->a);
    
    action_sepa(stack, size); //ok
    size2 = ft_lstsize(stack->a);
    sort_all(stack);
    
    while (i < size2)
    {
        ft_pb(stack, 1);
        i++;
    }
    sort_all(stack);
    
   
}


