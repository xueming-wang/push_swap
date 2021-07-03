/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:34 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/03 19:53:07 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
//将 a 栈所有元素上移（前移）一位，第一个元素变为最后一位元素。
// rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
//将 b 栈所有元素上移（前移）一位，第一个元素变为最后一位元素。
#include "push_swap.h"

void    ft_ra(t_stack *stack, int print)
{
    t_list *tmp;

    if (!stack->a || !stack->a->next)
        return;
    tmp = stack->a; //保存第一个元素
    stack->a = stack->a->next; //第二个元素变成第一个元素，第一个改变
    tmp->next = NULL;  //第一个元素的下一位是null
    ft_lstadd_back(&stack->a, tmp); //把第一个元素加到链表最后一位
    if (print == 1)
        printf("ra\n");
}


void    ft_rb(t_stack *stack, int print)
{
    t_list *tmp;

    if (!stack->b || !stack->b->next)
        return;
    tmp = stack->b; 
    stack->b = stack->b->next;
    tmp->next = NULL; 
    ft_lstadd_back(&stack->b, tmp);
    if (print == 1)
        printf("rb\n");
}

void    ft_rr(t_stack *stack, int print)
{
    ft_ra(stack, print);
    ft_rb(stack, print);
    if (print == 1)
        printf("rr\n");
}
