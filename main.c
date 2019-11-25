/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:04:20 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/25 21:39:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd1;
	int fd2;
	char *linefd1;
	char *linefd2;
	int i;
	int j;

	fd1 = open("./texte1", O_RDONLY);
	fd2 = open("./texte2", O_RDONLY); 
	i = 1;
	j = 1;
	while (i > 0 || j > 0)
	{
		i = get_next_line(fd1, &linefd1);
		j = get_next_line(fd2, &linefd2);
		printf("FD 1 = %s\n", linefd1);
		printf("FD 2 = %s\n", linefd2);
	}
	return(0);
}
