/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:45:44 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/25 18:26:09 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
// 交换 a栈最顶部的两个元素（【0】，【1】） 如果是0或者1个元素则不运行
// swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
// 交换 b 栈最顶部的两个元素（【0】，【1】）如果是0或者1个元素则不运行


#include "push_swap.h"


void    ft_sa(t_stack *stack)
{
        void *tmp;  //保存数

        if (!stack->a || !stack->a->next)
            return;
        tmp = stack->a->content;
        stack->a->content = stack->a->next->content;
        stack->a->next->content = tmp;
        printf("sa\n");
}    

void    ft_sb(t_stack *stack)
{
        void *tmp;

        if (!stack->b || !stack->b->next)
            return;
        tmp = stack->b->content;
        stack->b->content = stack->b->next->content;
        stack->b->next->content = tmp;
        printf("sb\n");
}

void    ft_ss(t_stack *stack)
{
    ft_sa(stack);
    ft_sb(stack);
    printf("ss\n");
}

// int main()
// {
      
//     t_stack *nbr;

//     nbr = malloc(sizeof(t_stack));
//     nbr->b = ft_lstnew((int *)1);
//     nbr->b->next= ft_lstnew((int *)2);
//      ft_sb(nbr);
//      printf("%d\n", (int)nbr->b->content);
//     printf("%d\n", (int)nbr->b->next->content);
// }