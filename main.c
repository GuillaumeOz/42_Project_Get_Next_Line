/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:33:37 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/26 16:18:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*string;
	int		fd;
	int		fd1;
	int		fd2;
	int		ret;

	if (ac == 4)
	{
		fd = open(av[1] ,O_RDONLY);
		fd1 = open(av[2] ,O_RDONLY);
		fd2 = open(av[3] ,O_RDONLY);
		ret = get_next_line(fd, &string);
		printf("%s\n", string);
		free(string);
		ret = get_next_line(fd1, &string);
		printf("%s\n", string);
		free(string);
		ret = get_next_line(fd2, &string);
		printf("%s\n", string);
		free(string);
		ret = get_next_line(fd, &string);
		printf("%s\n", string);
		free(string);
		ret = get_next_line(fd1, &string);
		printf("%s\n", string);
		free(string);
		ret = get_next_line(fd2, &string);
		printf("%s\n", string);
		free(string);
		return (ret);
	}
	else
	{
		ret = 1;
		fd = open(av[1] ,O_RDONLY);
		while (ret == 1)
		{
			ret = get_next_line(fd, &string);
			if (ret == 1)
				printf("%s\n", string);
			else if (ret == 0)
				printf("%s", string);
			free(string);
			string = NULL;
		}
		close(fd);
		return (ret);
	}
	return (0);
}
