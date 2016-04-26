/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 09:57:59 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_obj				*save_vertices(t_conf *conf, t_obj **prev, char *line,
	t_obj **obj)
{
	t_obj			*r_prev;
	t_obj			*t_prev;
	char			**split;

	conf->pos.x = 0;
	if (!(r_prev = (t_obj *)malloc(sizeof(t_obj)))) malloc_error();
	t_prev = r_prev;
	split = ft_strsplit(line, ' ');
	while (split[conf->pos.x])
	{
		if (!(*prev))
			((*(obj)))->p_vertex = NULL;
		else
			((*(obj)))->p_vertex = ((*(prev)));
		((*(obj)))->c_vertex.x = conf->pos.x;
		((*(obj)))->c_vertex.y = conf->pos.y;
		((*(obj)))->c_vertex.z = ft_atoi(split[conf->pos.x++]);
		t_prev->c_vertex = ((*(obj)))->c_vertex;
		if (!(((*(obj)))->next = (t_obj *)malloc(sizeof(t_obj)))) malloc_error();
		if (!(t_prev->next = (t_obj *)malloc(sizeof(t_obj)))) malloc_error();
		((*(obj))) = ((*(obj)))->next;
		t_prev = t_prev->next;
		if (!(!((*(prev))))) ((*(prev))) = ((*(prev)))->next;
	}
	return (r_prev);
}

void				read_obj(t_conf *conf, char *path)
{
	int				fd;
	int				err;
	t_obj			*prev;
	t_obj			*tmp;
	char			*line;

	conf->pos.y = 0;
	prev = NULL;
	if ((fd = open(path, O_RDONLY)) == -1) open_error();
	if (!(conf->obj = (t_obj *)malloc(sizeof(t_obj)))) malloc_error();
	tmp = conf->obj;
	while ((err = get_next_line(fd, &line)) > 0)
	{
		prev = save_vertices(conf, &prev, line, &tmp);
		++conf->pos.y;
	}
	tmp->next = NULL;
	gnl_error(err);
	close(fd);
}

t_vec2				orthographic(t_conf conf, t_vec3 vertex)
{
	t_vec2			ret;

	translation(conf, &vertex);
	scale(conf, &vertex);
	rot_x(conf, &vertex);
	rot_y(conf, &vertex);
	rot_z(conf, &vertex);
	ret.x = vertex.x;
	ret.y = vertex.y;
	return (ret);
}
