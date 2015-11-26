/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:16:01 by spetit            #+#    #+#             */
/*   Updated: 2015/11/26 20:16:01 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
 
void ft_print_list(t_list *list)
{
    t_list *tmp = list;
    if(tmp == NULL)
      return(ft_putstr("!vide!"));
    while (tmp != NULL)
    {
        ft_putstr(tmp->content);
        ft_putchar('\n');
        tmp = tmp->next;
    }
}

void    swap_element(t_list *elem1, t_list *elem2)
{
  t_list        *tmp;
 
  tmp = elem1->content;
  elem1->content = elem2->content;
  elem2->content = tmp;
}

void    sort_list(t_list *list)
{
  t_list        *tmp;
  static int state = 1;
 
  while (state != 0)
    {
      state = 0;
      tmp = list;
      while (tmp->next != NULL)
        {
          if (ft_strcmp((tmp->content),(tmp->next->content)) > 0)
            {
              swap_element(tmp, tmp->next);
              state++;
              tmp = tmp->next;
            }
          else
            tmp = tmp->next;
        }
    }
}
