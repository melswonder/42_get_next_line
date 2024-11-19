#include <stdio.h>
#include <stdlib.h>

char	*return_line(char *str)
{
	char	*dest;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] != '\n')
		{
			dest[i++] = '\n';
			break;	
		}
		dest[i] = str[i];
		i++;
	}
	// dest[i++] = '\n'; // 改行がないときに改行が追加されてしまう
	dest[i] = '\0';
	return (dest);
}
int main(void)
{
	char str[] = "hello";
	printf("%s",return_line(str));
}