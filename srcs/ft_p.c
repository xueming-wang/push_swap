/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/22 18:57:31 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
// 将 b 栈的元素【0】推到 a 栈【0】 如果b 栈没有元素 不运行
//push b - prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
//// 将 a 栈的元素【0】推到 b 栈【0】  如果 a 栈没有元素 不运行

#include "push_swap.h"

void    ft_pa(t_stack *stack)
{
    void *tmp;  //保存元素
    
    if (!stack->b)
        return;
    tmp = stack->b->next;  //b栈第二个元素保存；
    stack->b->next = stack->a; //b栈第二个元素变成a栈；
    stack->a = stack->b; //a栈的第一个元素位置放入b栈的第一个元素；
    stack->b = tmp;//b栈的第一个位置放入保存的第二个元素；

}

void    ft_pb(t_stack *stack)
{
    void *tmp;
    
    if (!stack->a)
        return;
    tmp = stack->a->next;
    stack->a->next = stack->b;
    stack->b = stack->a;
    stack->a = tmp;
}

// int main()
// {
//     t_stack *nbr;

//     nbr = malloc(sizeof(t_stack));
//     nbr->a = ft_lstnew((int *)1);
//     nbr->a->next = ft_lstnew((int *)2);
    
    
//     nbr->b = ft_lstnew((int *)3);
//     nbr->b->next = ft_lstnew((int *)4);
//     ft_pa(nbr);
//     printf("%d\n", (int)nbr->a->content);
//     printf("%d\n", (int)nbr->a->next->content);
//     printf("%d\n", (int)nbr->a->next->next->content);
    
//     printf("%d\n", (int)nbr->b->content);
   
    
   
// }