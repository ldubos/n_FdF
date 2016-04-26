/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 10:07:04 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SCALE_SPEED 0.5f
#define MOVE_SPEED 2.3f

int					key_hook(int keycode, t_conf *conf)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
	{
		conf->matrix.m11 += SCALE_SPEED;
		conf->matrix.m22 += SCALE_SPEED;
		conf->matrix.m33 += SCALE_SPEED;
	}
	if (keycode == 78)
	{
		conf->matrix.m11 -= SCALE_SPEED;
		conf->matrix.m22 -= SCALE_SPEED;
		conf->matrix.m33 -= SCALE_SPEED;
	}
	if (keycode == 123) conf->matrix.m14 -= MOVE_SPEED;
	if (keycode == 124) conf->matrix.m14 += MOVE_SPEED;
	if (keycode == 126) conf->matrix.m24 -= MOVE_SPEED;
	if (keycode == 125) conf->matrix.m24 += MOVE_SPEED;
	mlx_destroy_image(conf->env.mlx, conf->img.img);
	conf->img.img = mlx_new_image(conf->env.mlx, WIDTH, HEIGHT);
	draw_obj(*conf);
	mlx_clear_window(conf->env.mlx, conf->env.win);
	mlx_put_image_to_window(conf->env.mlx, conf->env.win, conf->img.img, 0, 0);
	return (0);
}
