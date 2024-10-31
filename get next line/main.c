/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:21:50 by aisidore          #+#    #+#             */
/*   Updated: 2024/07/23 18:58:48 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		count_line;
	//int		tab_fd[3];
	int		i;

	/*tab_fd[0] = open("test.txt", O_RDONLY);
	tab_fd[1] = open("test1.txt", O_RDONLY);
	tab_fd[2] = open("test2.txt", O_RDONLY);*/
	i = 0;
	if (fd == -1)
	{
		printf("Error opening the file\n");
		return (1);
	}
	printf("File descriptor : %d\n\n", fd);
	count_line = 0;
	while (1)
	{
		line = get_next_line(fd);
		//line = get_next_line(tab_fd[i++]);
		if (i == 3)
			i = 0;
		if (line == NULL)
			break ;
		count_line++;
		printf("[%d] : %s", count_line, line);
		free(line);
		line = NULL;
	}
	//close(fd);
	close(tab_fd[0]);
	close(tab_fd[1]);
	close(tab_fd[2]);
	return (0);
}
