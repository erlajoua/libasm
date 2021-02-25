# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);

int		TEST_STRLEN(void)
{
	int 	i;
	char	*strs[] = {"abc",
					"2147483647",
					"",
					"azertyiozpuixhqzuihdzquihdqzdzquih",
					"aa\0\0bbb\t\0tt",
					"z",
					"baaaaaaaaaaaaaa",
					"aaa\ttest\v\bbbbb",
					NULL};

	i = 0;
	while (strs[i])
	{
		printf("DIFF : |%zu| <--> |%zu|\n", strlen(strs[i]), ft_strlen(strs[i]));
		if (ft_strlen(strs[i]) != strlen(strs[i]))
		{
			printf("\nKO Test n°%d", i + 1);
			return (0);
		}
		printf("OK!\n");
		i++;
	}
	printf("NO DIFF ERROR\n");
	printf("FT_STRLEN SUCCES\n\n");
	printf("press a key to continue...\n");
	getchar();
	return (1);
}

int		TEST_STRDUP(void)
{
	int		i;
	char	*s;
	char	*strs[] = {"abc123def456",
					"214748364787897798879897",
					"",
					"TEST THIS STRING IS A TEST",
					"aa\0\0bbb\t\0tt",
					".",
					"$^$;,è-('èç'(é-&àç)",
					"aaa\ttest\t:\tbbbb",
					NULL};

	i = 0;
	while (strs[i])
	{
		s = ft_strdup(strs[i]);
		printf("DIFF : |%s| <--> |%s|\n", strs[i], s);
		if (s == NULL || strcmp(s, strs[i]))
		{
			printf("\nKO Test n°%d", i + 1);
			return (0);
		}
		printf("OK!\n");
		free(s);
		i++;
	}
	printf("NO DIFF ERROR\n");
	printf("FT_STRDUP SUCCES\n\n");
	printf("press a key to continue...\n");
	getchar();
	return (1);
}

int		TEST_STRCMP(void)
{
	int		i;
	char	*strs1[] = {"abc123def456",
					"214748364z787897798879897",
					"Z21474836478x897798879897",
					"",
					"TEST0 THIS STRING IS A TEST",
					"ay\0\0bbz\t\0tt",
					"Z",
					"$^$;,è-('èç'(é-&àç)",
					"aaa\ttest\t:\tbbbb",
					NULL};

	char	*strs2[] = {"abc123def4X6",
					"214748364787897798879897",
					"21474836478x897798879897",
					"",
					"TEST9 THIS STRING IS A TEST",
					"aa\0\0bbz\t\0tt",
					"z",
					"$^$;,è-('èç'(é-&àç)",
					"aaa\ttest\v:\tbbbb",
					NULL};
	i = 0;
	while (strs1[i])
	{
		printf("DIFF : |%d| <--> |%d|\n", strcmp(strs1[i], strs2[i]), ft_strcmp(strs1[i], strs2[i]));
		if ((strcmp(strs1[i], strs2[i])) != (ft_strcmp(strs1[i], strs2[i])))
		{
			printf("\nKO Test n°%d", i + 1);
			return (0);
		}
		printf("OK!\n");
		i++;
	}
	printf("NO DIFF ERROR\n");
	printf("FT_STRCMP SUCCES\n\n");
	printf("press a key to continue...\n");
	getchar();
	return (1);
}

int		TEST_RDWR(void)
{
	int 	i;
	char	c;
	int		byte;
	int		pid;
	char	*strs[] = {"abc",
					"2147483647",
					"",
					"azertyiozpuixhqzuihdzquihdqzdzquih",
					"aa\0\0bbb\t\0tt",
					"z",
					"baaaaaaaaaaaaaa",
					"aaa\ttest\t\bbbbb",
					NULL};

	i = 0;
	printf("TEST STDIN READ/WRITE (press Ctrl+D to end)\n");
	while ((byte = ft_read(0, &c, 1)) > 0)
		ft_write(1, &c, 1);
	printf("/!\\ CHECK IF THERE IS NO ERROR /!\\\n\n");
	printf("\nTESTS WRITE STDOUT\n");
	while (strs[i])
	{
		write(1, "REAL: ", 6);
		write(1, strs[i], strlen(strs[i]));
		write(1, "\n", 1);
		write(1, "FAKE: ", 6);
		ft_write(1, strs[i], strlen(strs[i]));
		write(1, "\n\n", 2);
		i++;		
	}
	printf("/!\\ CHECK IF THERE IS NO ERROR /!\\\n\n");
	printf("OTHERS TESTS...\n\n");
	if (ft_read(-1, &c, 1) != -1)
	{
		printf("KO : Bad return while reading on fd -1");
		return (0);
	}
	if (ft_read(0, &c, -1) != -1)
	{
		printf("KO : Bad return while reading -1 byte\n");
		return (0);
	}
	printf("NO DIFF ERROR\n");
	printf("FT_STRCMP SUCCES\n\n");
	printf("press a key to continue...\n");
	getchar();
	return (1);
}

int		TEST_STRCPY(void)
{
	int		i;
	char	*buff1;
	char	*buff2;
	char	*strs[] = {"abc",
					"2147483647",
					"",
					"azertyiozpuixhqzuihdzquihdqzdzquih",
					"aa\0\0bbb\t\0tt",
					"z",
					"baaaaaaaaaaaaaa",
					"aaa\ttest\t\bbbbb",
					NULL};

	i = 0;
	buff1 = malloc(500);
	buff2 = malloc(500);
	while (strs[i])
	{
		buff1 = strcpy(buff1, strs[i]);
		buff2 = ft_strcpy(buff2, strs[i]);
		printf("DIFF : |%s| <--> |%s|\n", buff1, buff2);
		if (strcmp(buff1, buff2))
		{
			printf("\nKO Test n°%d", i + 1);
			return (0);
		}
		printf("OK!\n");
		i++;
	}
	free(buff1);
	free(buff2);
	printf("NO DIFF ERROR\n");
	printf("FT_STRCPY SUCCES\n\n");
	printf("press a key to continue...\n");
	getchar();
	return (1);
}

int main(void)
{
	int ret = 0;

	ret += TEST_STRLEN();
	ret += TEST_STRDUP();
	ret += TEST_STRCMP();
	ret += TEST_RDWR();
	ret += TEST_STRCPY();
	if (ret == 5)
		printf("\nSUCCES!\nSUCCES!\nSUCCES!\nSUCCES!\nSUCCES!\n");
	else
		printf("\nSome tests have failed\n");
	return (0);
}
