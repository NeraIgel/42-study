#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

extern int	ft_printf(const char *, ...);

int	main(void)
{
	int		ret;
//	int		n[5] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
//	char	*s1;
//	char	*s2;

	printf("\n");
//	printf("%d\n", (unsigned long long)(n[0] - 1) >= INT_MAX);
//	printf("%d\n", (unsigned long long)n[0] >= INT_MAX);
//	printf("%d\n", (unsigned long long)n[0] + n[1] + n[2] + n[3] + n[4] >= INT_MAX);
//	printf("\n======================\n\n");
//	s1 = (char *)malloc(INT_MAX + 1);	memset(s1, 'a', INT_MAX);		s1[INT_MAX] = '\0';		printf("%zd\n", strlen(s1));	ret =  printf("%s", s1);	printf("(%d)\n", ret);	free(s1);
//	s2 = (char *)malloc(INT_MAX);		memset(s2, 'a', INT_MAX - 1);	s2[INT_MAX - 1] = '\0';	printf("%zd\n", strlen(s2));	ret =  printf("%s", s2);	printf("(%d)\n", ret);	free(s2);
//	printf("\n======================\n\n");
//	ret = printf(NULL);	printf("(%d)\n", ret);
	ret = printf("");	printf("(%d)\n", ret);
	ret = printf("a");	printf("(%d)\n", ret);
	ret = printf("%s", NULL);	printf("(%d)\n", ret);
	ret = printf("%c / %s / %p / %d / %i / %u / %x / %X / %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);	printf("(%d)\n", ret);
	printf("----------------\n");
	printf("[width]\t");	ret = printf("%2c / %2s / %2p / %2d / %2i / %2u / %2x / %2X / %2%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);	printf("(%d)\n", ret);
	printf("[.]\t");		ret = printf("%.c / %.s / %.p / %.d / %.i / %.u / %.x / %.X / %.%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);	printf("(%d)\n", ret);
	printf("[.n]\t");		ret = printf("%.3s / %.3d / %.3i / %.3u / %.3x / %.0X / %.3%", "test", 20, -20, -1, -1, 0);	printf("(%d)\n", ret);
	printf("[-]\t");		ret = printf("%-2c / %-2s / %-2p / %-2d / %-2i / %-2u / %-2x / %-2X / %-2%", 'a', "test", (void *)0xdeadc0de, 20, INT_MIN, -1, -1, 200000000);	printf("(%d)\n", ret);
	printf("[0]\t");		ret = printf("%02d / %02i / %02u / %02x / %02X / %02%", 20, -20, -1, -1, 200000000);	printf("(%d)\n", ret);
	printf("[-0]\t");		ret = printf("%-02% / %-02.3%");	printf("(%d)\n", ret);
	printf("[#]\t");		ret = printf("%#x / %#X / %#%", -1, 0);	printf("(%d)\n", ret);
	printf("[ ]\t");		ret = printf("% d / % d / % i / % %", 0, 20, -20);	printf("(%d)\n", ret);
	printf("[+]\t");		ret = printf("%+2d / %+2d / %+2i / %+2%", 0, 20, -20);	printf("(%d)\n", ret);
	printf("----------------\n");
	ret = printf("Hello %.2147483647d", 42);	printf("(%d)\n", ret);
	ret = printf("%.2147483647d", 42);	printf("(%d)\n", ret);
	ret = printf("%+.2147483646d", 42);	printf("(%d)\n", ret);
//	ret = printf("%.2147483646d", 42);	printf("(%d)\n", ret);
	printf("----------------\n");
	ret = printf("\n%d\n", printf("123%d123%2147483648d", 10, 10));	printf("(%d)\n", ret);
	ret = printf("123%d123%2147483648d", 10, 10);	printf("(%d)\n", ret);
	ret = printf("123%d123%d123%2147483648d", 10, 10, 10);	printf("(%d)\n", ret);
	printf("\n======================\n\n");
//	ret = ft_printf(NULL);	ft_printf("(%d)\n", ret);
	ret = ft_printf("");	ft_printf("(%d)\n", ret);
	ret = ft_printf("a");	ft_printf("(%d)\n", ret);
	ret = ft_printf("%s", NULL);	ft_printf("(%d)\n", ret);
	ret = ft_printf("%c / %s / %p / %d / %i / %u / %x / %X / %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);	ft_printf("(%d)\n", ret);
	ft_printf("----------------\n");
	ft_printf("[width]\t");	ret = ft_printf("%2c / %2s / %2p / %2d / %2i / %2u / %2x / %2X / %2%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);	ft_printf("(%d)\n", ret);
	ft_printf("[.]\t");		ret = ft_printf("%.c / %.s / %.p / %.d / %.i / %.u / %.x / %.X / %.%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);	ft_printf("(%d)\n", ret);
	ft_printf("[.n]\t");	ret = ft_printf("%.3s / %.3d / %.3i / %.3u / %.3x / %.0X / %.3%", "test", 20, -20, -1, -1, 0);	ft_printf("(%d)\n", ret);
	ft_printf("[-]\t");		ret = ft_printf("%-2c / %-2s / %-2p / %-2d / %-2i / %-2u / %-2x / %-2X / %-2%", 'a', "test", (void *)0xdeadc0de, 20, INT_MIN, -1, -1, 200000000);	ft_printf("(%d)\n", ret);
	ft_printf("[0]\t");		ret = ft_printf("%02d / %02i / %02u / %02x / %02X / %02%", 20, -20, -1, -1, 200000000);	ft_printf("(%d)\n", ret);
	ft_printf("[-0]\t");	ret = ft_printf("%-02% / %-02.3%");	ft_printf("(%d)\n", ret);
	ft_printf("[#]\t");		ret = ft_printf("%#x / %#X / %#%", -1, 0);	ft_printf("(%d)\n", ret);
	ft_printf("[ ]\t");		ret = ft_printf("% d / % d / % i / % %", 0, 20, -20);	ft_printf("(%d)\n", ret);
	ft_printf("[+]\t");		ret = ft_printf("%+2d / %+2d / %+2i / %+2%", 0, 20, -20);	ft_printf("(%d)\n", ret);
	ft_printf("----------------\n");
	ret = ft_printf("Hello %.2147483647d", 42);	ft_printf("(%d)\n", ret);
	ret = ft_printf("%.2147483647d", 42);	ft_printf("(%d)\n", ret);
	ret = ft_printf("%+.2147483646d", 42);	ft_printf("(%d)\n", ret);
//	ret = ft_printf("%.2147483646d", 42);	ft_printf("(%d)\n", ret);
	ft_printf("----------------\n");
	ret = ft_printf("\n%d\n", ft_printf("123%d123%2147483648d", 10, 10));	ft_printf("(%d)\n", ret);
	ret = ft_printf("123%d123%2147483648d", 10, 10);	ft_printf("(%d)\n", ret);
	ret = ft_printf("123%d123%d123%2147483648d", 10, 10, 10);	ft_printf("(%d)\n", ret);
	ft_printf("\n");
	return (0);
}
