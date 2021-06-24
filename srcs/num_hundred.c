/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:42:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/24 16:16:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libc.h>

void    ft_num_hundred(t_stack *stack)
{
    int size;
    size = ft_lstsize(stack->a); //有多少元素
    int i = 0;
   
    
    
   int smallest;//最大等于第一位
   
    if (stack)
    {
            while (stack->a)
            {
                smallest = ft_smallest(stack->a);
                if ((int)stack->a->content == smallest)
                {
                    ft_pb(stack);
                    printf("pb\n");
                }
                else 
                {
                    ft_ra(stack);
                    printf("ra\n");
                }
            }
            while (stack->b)
            {
                ft_pa(stack);
                printf("pa\n");
            }
    }
}

int main()
{
    t_stack *nbr;
    int size = ft_lstsize(nbr->a);
    int i = 0;
    nbr = malloc(sizeof(t_stack));
    if (!nbr)
        return (0);
    nbr->a = NULL;
    nbr->b = NULL;
    nbr->a = ft_lstnew((void *)100);
    nbr->a->next= ft_lstnew((void *)99);
    nbr->a->next->next= ft_lstnew((void *)521);
    nbr->a->next->next->next= ft_lstnew((void*)545);
    nbr->a->next->next->next->next= ft_lstnew((void *)44);
    nbr->a->next->next->next->next->next= ft_lstnew((void*)77);
    // nbr->a->next->next->next->next->next->next= ft_lstnew((void *)1);
    // nbr->a->next->next->next->next->next->next->next = ft_lstnew((void *)0);
    // nbr->a->next->next->next->next->next->next->next->next= ft_lstnew((void *)44);
    // nbr->a->next->next->next->next->next->next->next->next->next= ft_lstnew((void *)88);
    // nbr->a->next->next->next->next->next->next->next->next->next->next= ft_lstnew((void *)12);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)7);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)66);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)22);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)33);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)78);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)721);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)744);
    // nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = ft_lstnew((void *)54);
    ft_num_hundred(nbr);
//    while (i < size)
//    {
    printf("%d\n", (int)nbr->a->content);
    printf("%d\n", (int)nbr->a->next->content);
    printf("%d\n", (int)nbr->a->next->next->content);
    printf("%d\n", (int)nbr->a->next->next->next->content);
    printf("%d\n", (int)nbr->a->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
    // printf("%d\n", (int)nbr->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
        // nbr->a = nbr->a->next;
        // i++;
   //}
    
}