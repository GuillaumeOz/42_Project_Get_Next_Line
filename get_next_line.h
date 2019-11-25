/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:52:08 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/25 21:39:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# define FAILURE	-1
# define SUCCESS	0
# define VCT_DEFSIZE	128
# define VCT_DEFQUART	32

typedef struct		s_gnl
{
	struct s_vector	*vct;
	int				fd;
	struct s_gnl	*next;
	struct s_gnl	*prev;
}					t_gnl;

typedef struct		s_vector 
{
	char			*str;
	size_t			len;//len of the string
	size_t			size;//size of mallocated region
	size_t			quart;
}					t_vector;

/*
** allocates memory for the struct and initializes its members slen and msize
*/
//t_vct			*vct_new(size_t malloc_size);
/*
** inserts n char from the string src at the index n of our vector
*/
//t_vct			*vct_insert_nstr(t_vct *vct, char *src, size_t idx, size_t n);
/*
** inserts n char c at the index n of our vector
*/
//t_vct			*vct_insert_nchar(t_vct *vct, char c, size_t idx, size_t n);
/*
** removes n char from the index idx of vct->str
*/
//t_vct			*vct_cut_nfrom(t_vct *vct, size_t idx, size_t n);
/*
** frees the structure's memory
*/
//int				vct_del(t_vct *vct);

t_vector				*gnl_vct_new(size_t size);
int						gnl_vct_appnstr(t_vector *vct, char *addens, size_t n);
int						gnl_vct_cutnfrom(t_vector *vct, size_t idx, size_t n);
int						gnl_strnchr_idx(char *s, char c, size_t n, int mode);
int						get_next_line(int fd, char **line);

#endif
