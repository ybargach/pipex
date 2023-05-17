#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int	last(char *str, char c)
{
	int	a;
	int	b;
	int	i;

	b = 0;
	a = ft_strlen(str) - 1;
	i = a;
	while (str[a])
	{
		if (str[a] == c)
		{
			b++;
			a--;
		}
		else if (str[a] != c)
			break;
	}
	i = i - b;
	printf("%d\n", i);
	return (i);
}
int	beg(char *str, char c)
{
	int	a;
	int	b;
	int	i;
	int	len;

	a = 0;
	b = 0;
	len = ft_strlen(str);
	while (str[a])
	{
		if(str[a] == c)
		{
			b++;
			a++;
		}
		else
			break;
	}
	a = len - b;
	i = last(str + a, c);
	return (i);
}

char	*ft_send(char *s, char c)
{
	int a = last(s ,c);
	return (s);
}

int main()
{
	printf("%s", ft_send("a  youssef  h ", ' '));
}

// char	**ft_split(char const *s, char c)
// {
// 	char	**p;
// 	char	*str;

// 	str = ft_send(s, c);
// 	p =  malloc();
// }