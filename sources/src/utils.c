/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 00:35:25 by gbaud             #+#    #+#             */
/*   Updated: 2021/03/30 01:29:31 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*f;
	char	*s;
	size_t	i;

	i = 0;
	f = (char *)s1;
	s = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n && f[i] == s[i])
		i++;
	if (i == n)
		i--;
	return ((unsigned char)f[i] - (unsigned char)s[i]);
}

void	ft_free_strs_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		ft_strs_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *fi, const char *se, size_t len)
{
	const unsigned char	*f;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	f = (const unsigned char *)fi;
	s = (const unsigned char *)se;
	if (len == 0)
		return (0);
	while (i < len && f[i] == s[i] && f[i] != '\0')
		i++;
	if (i == len)
		i--;
	return ((unsigned char)f[i] - s[i]);
}
