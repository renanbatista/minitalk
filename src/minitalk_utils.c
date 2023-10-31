/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:17:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/10/10 23:22:34 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	sun;

	sun = 0;
	signal = 1;
	while ((*(nptr) >= 9 && *(nptr) <= 13) || *(nptr) == 32)
		nptr++;
	if (*(nptr) == '+' || *(nptr) == '-')
	{
		if (*(nptr) == '-')
			signal *= -1;
		nptr++;
		if (*(nptr) < 48 && *(nptr) > 57)
			return (0);
	}
	while (*(nptr) >= 48 && *(nptr) <= 57)
	{
		sun = (sun * 10) + *(nptr) - 48;
		nptr++;
	}
	return (sun * signal);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (len);
	else
	{
		while (--size && *(src + index))
		{
			*(dst + index) = *(src + index);
			index++;
		}
		*(dst + index) = '\0';
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	return (str);
}
