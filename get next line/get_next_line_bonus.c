/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:50 by aisidore          #+#    #+#             */
/*   Updated: 2024/07/23 18:56:42 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Partie bonusbasin[fd]
//Bien relire les consignes avant de push !!!
//if BUFFER_SIZE too large : no read. Why ? Comportement attendu de gnl ?
// free dst et src pour ft_memmove ?

#include "get_next_line_bonus.h"

void	*ft_free(char **ptr_basin)
{
	if (*ptr_basin != NULL)
	{
		free(*ptr_basin);
		*ptr_basin = NULL;
	}
	return (NULL);
}

static char	*read_one_block(int fd)
{
	char	*block;

	block = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (block == NULL)
		return (NULL);
	if (read(fd, block, BUFFER_SIZE) < 1)
		ft_free(&block);
	return (block);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*unc_dst;
	unsigned char	*unc_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	unc_dst = (unsigned char *)dst;
	unc_src = (unsigned char *)src;
	i = 0;
	if (unc_dst <= unc_src)
	{
		while (i < n)
		{
			unc_dst[i] = unc_src[i];
			i++;
		}
		return (dst);
	}
	while (i < n)
	{
		unc_dst[n - i - 1] = unc_src[n - i - 1];
		i++;
	}
	return (dst);
}

static char	*split_basin_line(char **ptr_basin)
{
	size_t	len;
	char	*line;
	char	*nl_pos;
	char	*new_basin;

	nl_pos = ft_strchr(*ptr_basin, '\n');
	len = nl_pos - *ptr_basin + 1;
	line = ft_memmove(ft_calloc(len + 1, sizeof(char)), *ptr_basin, len);
	new_basin = ft_dup(nl_pos + 1);
	ft_free(ptr_basin);
	*ptr_basin = new_basin;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*basin[10000];
	char		*block;
	char		*last_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(&basin[fd]));
	block = read_one_block(fd);
	if (block == NULL && ft_strchr(basin[fd], '\n') == NULL)
	{
		last_line = ft_dup(basin[fd]);
		if (basin[fd] != NULL)
			ft_free(&basin[fd]);
		return (last_line);
	}
	basin[fd] = ft_join_free(basin[fd], block);
	if (ft_strchr(basin[fd], '\n'))
		return (split_basin_line(&basin[fd]));
	else
		return (get_next_line(fd));
}
