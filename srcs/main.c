/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:34:01 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 10:07:26 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				init_conf(t_conf *conf)
{
	conf->env.mlx = mlx_init();
	conf->env.win = mlx_new_window(conf->env.mlx, WIDTH, HEIGHT, "FdF");
	conf->img.img = mlx_new_image(conf->env.mlx, WIDTH, HEIGHT);
	conf->img.data = mlx_get_data_addr(conf->img.img, &conf->img.bpp,
		&conf->img.sl, &conf->img.endian);
	conf->matrix = (t_matrix4x4){.m11 = 1, .m12 = 0, .m13 = 0, .m14 = 0,
								 .m21 = 0, .m22 = 1, .m23 = 0, .m24 = 0,
							 	 .m31 = 0, .m32 = 0, .m33 = 1, .m34 = 0,
							 	 .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 1};
}

int					main(int ac, char **av)
{
	t_conf			conf;

	arg_error(ac);
	init_conf(&conf);
	read_obj(&conf, av[1]);
	/* mlx_hook(); */
	mlx_loop(conf.env.mlx);
	return (0);
}
