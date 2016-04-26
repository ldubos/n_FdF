/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:56:59 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 10:08:57 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				put_pixel(t_img *img, t_vec2 p, int color)
{
	char			*pixel;

	if ((p.x < WIDTH && p.y < HEIGHT) && (p.x >= 0 && p.y >= 0))
	{
		pixel = img->data + p.y * img->sl + (img->bpp / 8) * p.x;
		pixel[2] = (char)(color >> 16);
		pixel[1] = (char)(color >> 8);
		pixel[0] = (char)(color);
	}
}

void				draw_line_pta(t_img *img, t_vec2 a, t_vec2 b,
		int color)
{
	t_vec2			p;

	p.x = a.x;
	while (p.x < b.x)
	{
		p.y = a.y + ((b.y - a.y) * (p.x - a.x)) / (b.x - a.x);
		put_pixel(img, p, color);
		++p.x;
	}
}

void				draw_line_ptb(t_img *img, t_vec2 a, t_vec2 b,
		int color)
{
	t_vec2			p;

	p.y = a.y;
	while (p.y < b.y)
	{
		p.x = a.x + ((b.x - a.x) * (p.y - a.y)) / (b.y - a.y);
		put_pixel(img, p, color);
		++p.y;
	}

}

void				draw_line(t_conf *conf, t_vec2 a, t_vec2 b, int color)
{
	t_vec2			p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.x < 0 ? p.x = -p.x : p.x;
	p.y < 0 ? p.y = -p.y : p.y;
	if (p.x > p.y)
		if (a.x <= b.x)
			draw_line_pta(&conf->img, a, b, color);
		else
			draw_line_pta(&conf->img, b, a, color);
	else
		if (a.y < b.y)
			draw_line_ptb(&conf->img, a, b, color);
		else
			draw_line_ptb(&conf->img, b, a, color);
}

void				draw_obj(t_conf conf)
{
	while (conf.obj != NULL)
	{
		if (conf.obj->c_vertex.y != 0)
			draw_line(&conf, orthographic(conf, conf.obj->c_vertex),
					  orthographic(conf, conf.obj->p_vertex->c_vertex),
					  0xFF8865);
		if (conf.obj->next != NULL &&
			 conf.obj->next->c_vertex.y == conf.obj->c_vertex.y)
			draw_line(&conf, orthographic(conf, conf.obj->c_vertex),
					  orthographic(conf, conf.obj->next->c_vertex),
					  0x998535);
		conf.obj = conf.obj->next;
	}
}
