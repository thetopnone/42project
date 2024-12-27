/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:07:44 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:34 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	char_check;

	char_check = 1;
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			char_check = 1;
		else
			return (0);
		str++;
	}
	return (char_check);
}
/*
int	main(void)
{
	char str[] = "thisis@stringG";

	printf("%d", ft_str_is_alpha(str));
	return (0);
}*/
