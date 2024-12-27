/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:45:38 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/21 11:21:34 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;

	diff = *s1 - *s2;
	while (*s1 >= 0 && *s2 >= 0)
	{
		diff = *s1 - *s2;
		if (*s1 != *s2)
			return (diff);
		if (*s1 == 0 && *s2 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (diff);
}

/*int main(void)
{
	char	str1[5] = "Hello";
	char	str2[6] = {

	printf("%d", ft_strcmp(str1, str2));
	return (0);
}*/
