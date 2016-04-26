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
	conf->width = 1920;
	conf->height = 1080;
	conf->env.mlx = mlx_init();
	conf->env.win = mlx_new_window(conf->env.mlx, conf->width, conf->height,
		"FdF");
	conf->img.img = mlx_new_image(conf->env.mlx, conf->width, conf->height);
	conf->img.data = mlx_get_data_add(conf->img.img, &conf->img.bpp,
		&conf->img.sl, &conf->img.endian);
	/* mlx_hook(); */
}

int					main(int ac, char **av)
{
	t_conf			conf;

	arg_error(ac);
	init_conf(&conf);
	read_obj(&conf, av[1]);
	mlx_loop(conf.env.mlx);
	return (0);
}
