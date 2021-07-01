/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:48:16 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/25 18:25:55 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 //reverse rotate a - décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
 //反响将 a 栈所有元素下移（后移）一位，最后一位元素变为第一个元素。
 //reverse rotate b - décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
 //反响将 b 栈所有元素下移（后移）一位，最后一位元素变为第一个元素。

 #include "push_swap.h"

 void   ft_rra(t_stack *stack)
 {
     t_list *last_tmp;
     t_list *tmp;
     
     if (!stack->a || !stack->a->next)
        return; //保存第一个地址
    last_tmp = ft_lstlast(stack->a);//走到最后一个元素保存最后一个元素
    tmp = stack->a;                 //保存最后一位的前一位元素
    while (tmp->next->next)
        tmp = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(&stack->a,last_tmp); //把最后一位加到最前面
    printf("rra\n");
}

 void   ft_rrb(t_stack *stack)
 {
    t_list *last_tmp;
    t_list *tmp;
     
    if (!stack->b || !stack->b->next)
        return; 
    last_tmp = ft_lstlast(stack->b);
    tmp = stack->b; 
    while (tmp->next->next)
        tmp = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(&stack->b,last_tmp); 
    printf("rrb\n");
    
 }

 void   ft_rrr(t_stack *stack)
 {
     ft_rra(stack);
     ft_rrb(stack);
     printf("rrr\n");
 }

//  int main()
// {
      
//     t_stack *nbr;

//     nbr = malloc(sizeof(t_stack));
//     nbr->b = ft_lstnew((int *)1);
//     nbr->b->next= ft_lstnew((int *)2);
//     nbr->b->next->next = ft_lstnew((int *)3);
//      ft_rrb(nbr);
//      printf("%d\n", (int)nbr->b->content);
//     printf("%d\n", (int)nbr->b->next->content);
//      printf("%d\n", (int)nbr->b->next->next->content);
// }