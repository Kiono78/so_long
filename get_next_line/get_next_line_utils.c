/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:25 by bterral           #+#    #+#             */
/*   Updated: 2021/12/02 10:01:35 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	s_len;
	size_t	i;
	char	*output;

	if (!s)
		return (NULL);
	sub_len = 0;
	s_len = ft_strlen(s);
	while (sub_len < len && *(s + sub_len) != '\0' && start < s_len)
		sub_len++;
	output = (char *)malloc(sizeof(*s) * (sub_len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		*(output + i) = *(s + start + i);
		i++;
	}
	*(output + i) = '\0';
	return (output);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 ||!s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		*(output + i) = *(s1 + i);
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		*(output + i) = *(s2 + (i - s1_len));
		i++;
	}
	*(output + i) = 0;
	return (output);
}

char	*ft_strdup(const char *s)
{
	char	*output;
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (NULL);
	output = (char *)malloc(sizeof(*output) * (ft_strlen(s) + 1));
	if (output == NULL)
		return (NULL);
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*free_static(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}
