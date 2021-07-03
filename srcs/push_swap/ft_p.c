/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/03 19:53:01 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
// 将 b 栈的元素【0】推到 a 栈【0】 如果b 栈没有元素 不运行
//push b - prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
//// 将 a 栈的元素【0】推到 b 栈【0】  如果 a 栈没有元素 不运行

#include "push_swap.h"

void    ft_pa(t_stack *stack, int print)
{
    void *tmp;  //保存元素
    
    if (!stack->b)
        return;
    tmp = stack->b->next;  //b栈第二个元素保存；
    stack->b->next = stack->a; //b栈第二个元素变成a栈；
    stack->a = stack->b; //a栈的第一个元素位置放入b栈的第一个元素；
    stack->b = tmp;//b栈的第一个位置放入保存的第二个元素；
    if (print == 1)
        printf("pa\n");

}

void    ft_pb(t_stack *stack, int print)
{
    void *tmp;
    
    if (!stack->a)
        return;
    tmp = stack->a->next;
    stack->a->next = stack->b;
    stack->b = stack->a;
    stack->a = tmp;
    if (print == 1)
        printf("pb\n");
}


