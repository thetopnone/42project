/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:54 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/14 17:10:47 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void	ft_swap(int *x, int *y)
{
	int	temp_val;

	temp_val = *x;
	*x = *y;
	*y = temp_val;
}

int	ft_nums_in_position(int *tab, int size)
{
	int	pos_in_arr;
	int	nums_in_pos;

	nums_in_pos = 0;
	pos_in_arr = size - 1;
		while (*(tab + pos_in_arr) >= *(tab + pos_in_arr - 1))
		{
			nums_in_pos++;
			pos_in_arr--;
		}
	return (nums_in_pos);

}
void	ft_sort_int_tab(int *tab, int size)
{
	int	counter;

	while (ft_nums_in_position(tab, size) != 4)
	{
		counter = 0;
		if (*tab > *(tab + 1))
		{
			ft_swap(tab , (tab + 1));
			tab++;
			counter++;
		}
		else
			tab = tab - counter;
	}
}

int	main(void)
{
	int arr[5] = { 1, 2, 7, 6 ,1};
	int	i = 0;

	while (i < 5)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_sort_int_tab(arr , 5);
	while (i < 5)
	{
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}
