/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:55 by aisidore          #+#    #+#             */
/*   Updated: 2024/07/16 18:02:17 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h> 

void	*ft_free(char **ptr_basin);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t n, size_t sizof);
char	*ft_join_free(char *str1, char *str2);
char	*ft_dup(char const *str);
char	*ft_strchr(char const *str, int c);
char	*get_next_line(int fd);

#endif