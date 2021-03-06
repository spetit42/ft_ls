/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:15:35 by spetit            #+#    #+#             */
/*   Updated: 2015/11/26 20:15:37 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

struct dirent   *ls_direntcpy(struct dirent *src)
{
    struct dirent   *cpy;

    cpy = (struct dirent*)malloc(sizeof(struct dirent));
    if (cpy)
    {
        cpy->d_ino      = src->d_ino;
        cpy->d_reclen   = src->d_reclen;
        cpy->d_namlen   = src->d_namlen;
        cpy->d_type     = src->d_type;
        ft_strcpy(cpy->d_name, src->d_name);
        return (cpy);
    }
    return (NULL);
}

int ft_firstchar(char *str, char c)
{
    if (str != NULL)
    {  
        if (str[0] == c)
            return (-1);
        else
            return(0);
    }
    return(0);
}

char *get_target(char *str)
{
    if (ft_firstchar(str, '-'))
        return("NO");
    else
        return(str);
}

char get_option(char *str)
{
    char tmp[6] = "arlRt";
    int i;

    i = 0;
    if (ft_firstchar(str, '-'))
        i++;
    if (ft_strchr(tmp, str[i]))
        return(str[i]); 
    else
        return('o');
}   

int ft_read(DIR *rep, struct dirent* fichierLu, int sort)
{
    t_list *list;
    struct dirent *data;

    list = NULL;
    if (rep == NULL)
        return(0);
    while ((fichierLu = readdir(rep)) != NULL)
    {
        while (ft_firstchar(fichierLu->d_name, '.'))
        {
            fichierLu = readdir(rep);
            if (fichierLu == NULL)
                break;
        }
        if (fichierLu != NULL)
        {
            data = ls_direntcpy(fichierLu);
            ft_list_push_front(&list, data->d_name);
            //ft_print_list(list);
            // ft_putstr(fichierLu->d_name);
            // ft_putchar('\n');
        }
        else
        {   
            // sort_list(list);
            // ft_print_list(list);
            return(0);
        }     
    }
    if (sort == 1)
        sort_rev_list(list);
    else
        sort_list(list);
    ft_print_list(list);
    if (closedir(rep) == -1)
    {
        ft_putstr("Close Error");
        return(-1);
    }
    return(1);
}

int main(int ac, char **av)
{
    char *target;
	DIR *rep = NULL;
    struct dirent* fichierLu = NULL;
    int i;
    int sort;

    sort = 0;
    i = 1;
    target = NULL;
   
    if (ac == 1)
        rep = opendir(".");
    else
        while (av[i])
        { 
            
            if (get_target(av[i]) == av[i])
            {
                target = get_target(av[i]);
                rep = opendir(target);
                if (rep == NULL)
                {
                    ft_putstr("ls: ");
                    perror(target);
                }
            }
            else 
            {
                if (get_option(av[i]) == 'r')
                    sort++;
            }
            i++;
        }
    ft_read(rep, fichierLu, sort);
	return (0);
}
