/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:11:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/01 12:48:22 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_biggest(t_list *a)
{
    int biggest;
    t_list *tmp;
    
    tmp = a;
    biggest = (int)tmp->content;
    while (tmp)
    {
        if (biggest < (int)tmp->content)
            biggest = (int)tmp->content;
        tmp = tmp->next;
    }
    return (biggest);
}

int    ft_smallest(t_list *a)
{
    int smallest;
    t_list *tmp;
    
    tmp = a;
    smallest = (int)tmp->content;
    while (tmp)
    {
        if (smallest > (int)tmp->content)
            smallest = (int)tmp->content;
        tmp = tmp->next;
    }
    return (smallest);
}
static void  stack_to_tab(t_list *a, int *tab, int size)
{
    
    int i;
    t_list *tmp;
    
    i = 0;
    tmp = a;
    while (i < size)
    {
        tab[i] = (int)tmp->content;
        i++;
        tmp = tmp->next;
    }
}

static void  ft_sort_tab(int *tab, int size)
{
    int i;
    int j;
    int tmp;
    
    i = 0;
    j = 0;
    tmp = 0;

    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;   
    }
}

int  find_mid(t_stack *stack, t_list *a_b, int size)
{
    int *tab;
    int mid;
  
    
    tab = malloc(sizeof(int) *size);
    if (!tab)
        quit_error(stack);
    ft_bzero(tab, sizeof(int) * size);
    stack_to_tab(a_b, tab, size);
    ft_sort_tab(tab, size);
    mid = tab[size / 2];
    free(tab);
    return (mid);
}

void    b_to_a(t_stack *stack)
{
    int tmp;
    int biggest;
    int smallest;

   
    tmp = (int)stack->a->content;
    while (stack->b)
     {
         biggest = ft_biggest(stack->b);
         smallest = ft_smallest(stack->b);
        if ((int)stack->b->content  == smallest)
        {
            ft_pa(stack);
            ft_ra(stack);
        }
        else if ((int)stack->b->content == biggest)
            ft_pa(stack);
        else 
            ft_rb(stack);
}
    while ((int)stack->a->content != tmp)
            ft_ra(stack);
} 