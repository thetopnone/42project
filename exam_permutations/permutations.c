#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	factorial(size_t num)
{
	size_t	res;

	res = 1;
	if (num == 0 || num == 1)
		return (res);
	while (num > 1)
	{
		res *= num;
		num--;
	}
	return (res);
}

int	swap(char *a ,char *b)
{
	char	temp;

	if (a == b)
		return (0);
	temp = *a;
	*a = *b;
	*b = temp;
	return (0);
}

int		ft_recursion(char **arr, char *str, size_t cur, size_t target)
{
	if (cur_let == target)
	{
		*arr = strdup(str);
		arr++;
		return (0);
	}
	if (str[cur] && str[target])
	{
		ft_recursion(arr, str, cur
	}
}

char	**ft_permutations(char *argv)
{
	char	**arr;
	size_t	total;

	total = factorial(strlen(argv));
	arr = calloc(total, sizeof(char *));
	ft_recursion(arr, cur_let, target);
}

int	main(int argc, char **argv)
{}
