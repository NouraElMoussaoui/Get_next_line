/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:35:37 by nel-mous          #+#    #+#             */
/*   Updated: 2022/11/14 13:04:35 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2)+1);
	if (!new)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j])
		new[i++] = s2[j];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		n;
	char	*dst;

	i = 0;
	n = ft_strlen(src);
	dst = (char *)malloc(n * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	int				j;

	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		sub = (char *)malloc (ft_strlen(s) - start + 1);
	else
		sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start] && len--)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}
