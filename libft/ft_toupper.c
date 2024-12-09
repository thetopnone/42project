/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:30:21 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/09 20:39:10 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c) == 0)
		return (c);
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}
