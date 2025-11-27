#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_permutations(char *s, char *b, int *used, size_t pos, size_t len)
{
	size_t	i;

	i = 0;
	if (pos == len)
	{
		b[len] = 0;
		puts(b);
		return ;
	}
	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			b[pos] = s[i];
			ft_permutations(s, b, used, pos + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*b;
	size_t	len;
	int		*used;

	len = 0;
	b = NULL;
	used = NULL;
	if (argc == 2)
	{
		len = strlen(argv[1]);
		b = calloc(len + 1, sizeof(char));
		used = calloc(len, sizeof(int));
		ft_permutations(argv[1], b, used, 0, len);
	}
}
