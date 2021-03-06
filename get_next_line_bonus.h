/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:52:08 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/27 19:06:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define FAILURE	-1
# define SUCCESS	0
# define VCT_DEFSIZE	128
# define VCT_DEFQUART	32

typedef struct			s_gnl
{
	struct s_vector		*vct;
	int					fd;
	struct s_gnl		*next;
	struct s_gnl		*prev;
}						t_gnl;

typedef struct			s_vector
{
	char				*str;
	size_t				len;
	size_t				size;
	size_t				quart;
}						t_vector;

t_vector				*gnl_vct_new(size_t size);
int						gnl_vct_appnstr(t_vector *vct, char *addens, size_t n);
int						gnl_vct_cutnfrom(t_vector *vct, size_t idx, size_t n);
int						gnl_strnchr_idx(char *s, char c, size_t n, int mode);
int						get_next_line(int fd, char **line);

#endif
