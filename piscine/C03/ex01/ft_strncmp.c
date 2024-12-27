/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:05:08 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/21 17:23:15 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	diff;

	diff = 0;
	while (n > 0)
	{
		diff = *s1 - *s2;
		if (diff != 0)
			return (diff);
		s1++;
		s2++;
		n--;
		if (!(*s1 || *s2) && n > 0)
		{
			diff = *s1 - *s2;
			break ;
		}
	}
	return (diff);
}
/*
int main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Helloo";

	printf("%d", ft_strncmp(str1, str2, 6));
	return (0);
}*/
