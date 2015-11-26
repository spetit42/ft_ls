#ifndef FT_LS_h
#define FT_LS_h

#include "libft.h"
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <pwd.h>

void    sort_list(t_list *list);
void	ft_print_list(t_list *list);

// typedef struct	s_options
// {
// 	unsigned char	l_opt;
// 	unsigned char	R_opt;
// 	unsigned char	a_opt;
// 	unsigned char	r_opt;
// 	unsigned char	t_opt;
// }				t_options;

// typedef struct	s_log
// {
// 	char	*name;
// 	char	*permissions;
// 	time_t	last_modification;
// }				t_log;


#endif
