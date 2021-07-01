/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:11:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/22 19:30:47 by xuwang           ###   ########.fr       */
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