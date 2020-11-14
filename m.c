#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);

int		main(int ac, char **av)
{
	int a;
	char *str;

	str = "uo";

	a = 10;
	(void)ac;
	ft_printf(av[4], atoi(av[1]), atoi(av[2]), &a + 10);
	printf("\n-----------------------\n");
	printf(av[4], atoi(av[1]), atoi(av[2]), &a + 10);
	printf("\n");
/*	printf("-----------------------\n");
	printf("%1d-----%.3d-----%.5d\n", atoi(av[1]), atoi(av[2]), atoi(av[3]));
	printf("-----------------------\n");
	printf("%5.s-----%.s-----%.5s\n", av[1], av[2], av[3]);
	ft_printf("%d\n", 1);*/
	return (0);
}
