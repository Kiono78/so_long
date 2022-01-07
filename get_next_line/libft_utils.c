/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:53:21 by bterral           #+#    #+#             */
/*   Updated: 2022/01/07 16:05:32 by bterral          ###   ########.fr       */
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
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			return (i);
	i++;
	}
	return (-1);
}
