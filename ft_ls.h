/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:03:57 by julee             #+#    #+#             */
/*   Updated: 2018/10/23 15:28:53 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <string.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

char					g_flag[6];
long long int			g_total;

typedef struct			s_len
{
	int					link;
	int					usr;
	int					grp;
	int					majordev;
	int					minordev;
	int					size;
}						t_len;

t_len					g_len;

typedef struct			s_vec
{
	int					size;
	char				*filename;
	char				*linkname;
	unsigned short int	filemode;
	char				*usrname;
	char				*grpname;
	int					nlink;
	long long int		filesize;
	long int			mtime;
	long int			nanosec;
	int					major_devnum;
	int					minor_devnum;
	char				*path;
}						t_vec;

typedef struct			s_dir
{
	DIR					*dirp;
	struct dirent		*dp;
	struct stat			buf;
	char				*path_name;
}						t_dir;

void					ft_ls(char *path);
void					sort_n_print(t_vec **filedata, char *path);
void					freer(t_vec **filedata);
void					freer2(t_vec **filedata, int i);

int						recog_flag(char *str);
void					check_flag(char c);
void					flag_initializer(void);

int						sizeof_dir(char *path);
t_vec					*malloc_list(int size);
void					put_filedata(t_vec *filedata, struct stat buf);
char					*join_path(char *path, char *filename);

void					print_mode(unsigned short int filemode);
void					print_time(long int time);
void					print_long_2(t_vec *filedata, int i);
void					print_long(t_vec *filedata, int i, int size);
void					print_data(t_vec *filedata);

void					recursive_ls(t_vec *filedata, char *path);

int						nbr_length(int n);
int						nbr_length_long(long long int n);

void					swap_value(t_vec *a, t_vec *b);
void					heapify(t_vec *filedata, int n, int i);
void					heap_sort(t_vec *filedata);

int						cmp_alpha(t_vec *filedata, int n, int i, int largest);
int						cmp_time_3(t_vec *filedata, int n, int i, int largest);
int						cmp_time_2(t_vec *filedata, int n, int i, int largest);
int						cmp_time(t_vec *filedata, int n, int i, int largest);

#endif
