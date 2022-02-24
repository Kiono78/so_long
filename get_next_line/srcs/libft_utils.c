/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:53:21 by bterral           #+#    #+#             */
/*   Updated: 2022/02/23 10:24:34 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
}

int	ft_strchr(const char *str, char character)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == character)
			return (i);
	i++;
	}
	return (-1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	if (num == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < num && str1[i] && str2[i])
		i++;
	if (i == num && num != 0)
		return (0);
	else
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
