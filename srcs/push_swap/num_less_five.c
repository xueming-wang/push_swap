/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_less_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:16:16 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/28 12:20:45 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_num_three(t_stack *stack)
{
    
    int	biggest;

	biggest = ft_biggest(stack->a);
	if (biggest == (int)stack->a->content)
	{
		ft_ra(stack);
		if ((int)stack->a->content > (int)stack->a->next->content)
			ft_sa(stack);
	}
	else if (biggest == (int)stack->a->next->content)
	{
		ft_rra(stack);
		if ((int)stack->a->content > (int)stack->a->next->content)
			ft_sa(stack);
	}
	else if (biggest == (int)stack->a->next->next->content)
    {
		if ((int)stack->a->content > (int)stack->a->next->content)
			ft_sa(stack);
    }
}

void    ft_num_five(t_stack *stack)
{
    int biggest;
    int smallest;
   
    biggest =  ft_biggest(stack->a);
    smallest = ft_smallest(stack->a);

        while (ft_lstsize(stack->b) != 2)
        {
            if ((int)stack->a->content == biggest || (int)stack->a->content == smallest)
                ft_pb(stack);
            else
                ft_ra(stack);
        }
    
    ft_num_three(stack);
    if ((int)stack->b->content > (int)stack->b->next->content)
        ft_sb(stack);
    ft_pa(stack);
    ft_pa(stack);
    ft_ra(stack);
}


// int main()
// {
      
//     t_stack *nbr;

//     nbr = malloc(sizeof(t_stack));
//     if (!nbr)
//         return (0);
//     nbr->a = NULL;
//     nbr->b = NULL;
//     nbr->a = ft_lstnew((void *)-100);
//     nbr->a->next= ft_lstnew((void *)45);
//     nbr->a->next->next= ft_lstnew((void *)3100);
//     nbr->a->next->next->next= ft_lstnew((void*)100);
//     // nbr->a->next->next->next->next= ft_lstnew((void *)88);
//     ft_num_five(nbr);
//     if (nbr->a->content)
//     printf("%d\n", (int)nbr->a->content);
//      if (nbr->a->content)
//     printf("%d\n", (int)nbr->a->next->content);
//      if (nbr->a->content)
//     printf("%d\n", (int)nbr->a->next->next->content);
//      if (nbr->a->content)
//     printf("%d\n", (int)nbr->a->next->next->next->content);
//     //  if (nbr->a->content)
//     // printf("%d\n", (int)nbr->a->next->next->next->next->content);

    
//}