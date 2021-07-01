/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:34 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/25 18:25:30 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
//将 a 栈所有元素上移（前移）一位，第一个元素变为最后一位元素。
// rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
//将 b 栈所有元素上移（前移）一位，第一个元素变为最后一位元素。
#include "push_swap.h"

void    ft_ra(t_stack *stack)
{
    t_list *tmp;

    if (!stack->a || !stack->a->next)
        return;
    tmp = stack->a; //保存第一个元素
    stack->a = stack->a->next; //第二个元素变成第一个元素，第一个改变
    tmp->next = NULL;  //第一个元素的下一位是null
    ft_lstadd_back(&stack->a, tmp); //把第一个元素加到链表最后一位
    printf("ra\n");
}


void    ft_rb(t_stack *stack)
{
    t_list *tmp;

    if (!stack->b || !stack->b->next)
        return;
    tmp = stack->b; 
    stack->b = stack->b->next;
    tmp->next = NULL; 
    ft_lstadd_back(&stack->b, tmp);
    printf("rb\n");
}

void    ft_rr(t_stack *stack)
{
    ft_ra(stack);
    ft_rb(stack);
    printf("rr\n");
}

// int main()
// {
//     t_stack *nbr;

//     nbr = malloc(sizeof(t_stack));
    
//     nbr->b = ft_lstnew((int *)1);
//     nbr->b->next = ft_lstnew((int *)2);
//     nbr->b->next->next = ft_lstnew((int *)3);

//     nbr->a = ft_lstnew((int *)4);
//     nbr->a->next = ft_lstnew((int *)5);
//     nbr->a->next->next = ft_lstnew((int *)6);
//      ft_rr(nbr);
//      printf("%d\n", (int)nbr->b->content);
//      printf("%d\n", (int)nbr->b->next->content);
//      printf("%d\n", (int)nbr->b->next->next->content);
//      printf("%d\n", (int)nbr->a->content);
//      printf("%d\n", (int)nbr->a->next->content);
//      printf("%d\n", (int)nbr->a->next->next->content);
   
// }