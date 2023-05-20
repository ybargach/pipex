/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:10:43 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:33:19 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strchr(char *str, int c)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		if (str[a] == c)
			return (str + a);
		a++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

char	*ft_strdup(char *str)
{
	int		a;
	int		b;
	char	*p;

	if (!str)
		return (NULL);
	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	a = 0;
	b = 0;
	while (str[a])
		p[b++] = str[a++];
	p[b] = '\0';
	return (p);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	int		a;
	int		b;
	int		c;
	char	*p;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(a * sizeof(char));
	if (!p)
		return (NULL);
	b = 0;
	c = 0;
	while (s1[b])
		p[c++] = s1[b++];
	b = 0;
	while (s2[b])
		p[c++] = s2[b++];
	p[c] = '\0';
	free(s1);
	return (p);
}
