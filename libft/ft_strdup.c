/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:06:48 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/14 21:36:35 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*refer;
	char	*scopy;

	refer = (char *)s;
	scopy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	ft_strlcpy(scopy, refer, ft_strlen(s) + 1);
	return (scopy);
}
