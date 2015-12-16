/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:15:49 by spetit            #+#    #+#             */
/*   Updated: 2015/11/26 20:15:50 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_h
#define FT_LS_h

#include "libft.h"
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <pwd.h>

void    sort_list(t_list *list);
void    sort_rev_list(t_list *list);
void	ft_print_list(t_list *list);

#endif
