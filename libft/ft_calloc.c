/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:06:17 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/14 19:46:57 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dummy_ptr;
	void	*buffer;
	size_t	size_max;

	size_max = (size_t)-1;
	dummy_ptr = malloc(1);
	buffer = NULL;
	if (nmemb == 0 || size == 0)
		return (dummy_ptr);
	if (size > size_max / nmemb)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
}
