#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

extern char	*get_next_line(int fd);

void	do_test(char *filename)
{
	int		fd;
	char	*line;

	printf("%s\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
	}
	close(fd);
	printf("\n================\n\n");
}

int	main(void)
{
	printf("\n================\n");
	do_test("./file1.txt");
	do_test("./file2.txt");
	do_test("./file3.txt");
	do_test("./file4.txt");
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	printf("\n");
	return (0);
}
