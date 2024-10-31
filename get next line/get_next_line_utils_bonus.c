/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:59 by aisidore          #+#    #+#             */
/*   Updated: 2024/07/16 17:51:28 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t sizof)
{
	unsigned char	*buffer;
	size_t			i;

	if (n < 1 || sizof < 1 || n > SIZE_MAX / sizof)
		return (NULL);
	i = 0;
	buffer = malloc(n * sizof);
	if (buffer == NULL)
		return (NULL);
	while (i < n * sizof)
		buffer[i++] = (unsigned char)0;
	return (buffer);
}

char	*ft_dup(char const *str)
{
	char	*copy_basin;
	size_t	i;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	copy_basin = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (copy_basin == NULL)
		return (NULL);
	while (str[i])
	{
		copy_basin[i] = str[i];
		i++;
	}
	return (copy_basin);
}

char	*ft_join_free(char *basin, char *block)
{
	size_t	len_basin;
	size_t	len_block;
	size_t	i;
	size_t	j;
	char	*new_basin;

	len_basin = ft_strlen(basin);
	len_block = ft_strlen(block);
	i = 0;
	j = 0;
	new_basin = ft_calloc(len_basin + len_block + 1, sizeof(char));
	while (i < len_basin && new_basin)
	{
		new_basin[i] = basin[i];
		i++;
	}
	while (j < len_block && new_basin)
	{
		new_basin[i + j] = block[j];
		j++;
	}
	ft_free(&basin);
	ft_free(&block);
	return (new_basin);
}

char	*ft_strchr(char const *str, int c)
{
	unsigned int	i;
	char			char_c;

	if (str == NULL)
		return (NULL);
	i = 0;
	char_c = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == char_c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == char_c)
		return ((char *)&str[i]);
	return (NULL);
}
