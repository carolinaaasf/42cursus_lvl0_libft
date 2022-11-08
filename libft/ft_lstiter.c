/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:18:53 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/08 22:21:50 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstliter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	if (!f || !lst)
		return ;
	while (lst)
	{
		aux = lst->next;
		f(lst->content);
		lst = aux;
	}
}
