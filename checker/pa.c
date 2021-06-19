/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/14 19:47:16 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
// 将 b 栈的元素【0】推到 a 栈【0】 如果b 栈没有元素 不运行

void    ft_pa(int *a, int *b)
{
    if (!*b)
        return;
    else
        a[0] = b[0];
        
}
