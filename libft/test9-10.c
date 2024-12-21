/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9-10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:33:57 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/19 19:45:13 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*dest;
	char	*src = "This is the original";

	printf("%li size of source\n", ft_strlen(src));
	printf("%s\n", src);
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (1);
	ft_memcpy(dest, src, ft_strlen(src));

}
