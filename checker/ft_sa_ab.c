/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:45:44 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/14 20:02:46 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
// 交换 a栈最顶部的两个元素（【0】，【1】） 如果是0或者1个元素则不运行
#include <libc.h>

void    ft_sa(int *a)
{
    int tmp;

    tmp = 0;
    if (!a)
        return ;
    if (!a[1])
        return;
    if (a[0] && a[1])
    {
        tmp = a[0];
        a[0] = a[1];
        a[1] = tmp;
    }
}    
void    ft_sb(int *b)
{
    int tmp;

    tmp = 0;
    if (!b)
        return;
    if (!b[0] || !b[1])
        return;
    if (b[0] && b[1])
    {
        tmp = b[0];
        b[0] = b[1];
        b[1] = tmp;
    }
}    

int main()
{
    int a[3] = {0, 2, 3};
    int *b;
    ft_sa(a);
    // ft_sb(b);
    printf("%d, %d, %d", a[0], a[1], a[2]);
 
}
