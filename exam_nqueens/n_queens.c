
int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
		return (1);
	n = itoa(argv[1]);
	ft_nqueens(n);
}
