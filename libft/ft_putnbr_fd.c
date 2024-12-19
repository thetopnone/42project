/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:24:45 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/19 17:49:11 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			numchar;
	unsigned int	abs_n;

	numchar = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		abs_n = -n;
	}
	else
		abs_n = n;
	if (abs_n > 9)
		ft_putnbr_fd((abs_n / 10), fd);
	numchar = abs_n % 10 + '0';
	write(fd, &numchar, 1);
}
