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
# include <fcntl.h>

ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

/*int main(void)
{
	char *s1 = "bonjour";
	char *s2 = "";
	char *s3 = "bonjour";
	char *s4 = "";
	printf("REAL : %d\n", strcmp(s1, s2));
	printf("FAKE : %d\n", ft_strcmp(s3, s4));
}
*/

/*int main(void)
{
	char *s = "z";
	printf("%s\n", ft_strdup(s));
}*/

/*int main(void)
{
	char c;

	while (ft_read(0, &c, 1))
		write(1, &c, 1);
	return (0);
}*/

int main(void)
{
	char *s = NULL;
	write(-4, s, 9);
	return (0);
}
