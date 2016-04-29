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

#define SCALE_U (t_matrix4x4){.m11 = 0.5f, .m12 = 0, .m13 = 0, .m14 = 0, \
							  .m21 = 0, .m22 = 0.5f, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0.5f, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define SCALE_D (t_matrix4x4){.m11 = -0.5f, .m12 = 0, .m13 = 0, .m14 = 0, \
							  .m21 = 0, .m22 = -0.5f, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = -0.5f, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define TRANS_L (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = -0.5f, \
							  .m21 = 0, .m22 = 0, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define TRANS_R (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0.5f, \
							  .m21 = 0, .m22 = 0, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define TRANS_U (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0, \
							  .m21 = 0, .m22 = 0, .m23 = 0, .m24 = -0.5f, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define TRANS_D (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0.5f, \
							  .m21 = 0, .m22 = 0, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define TRANS_D (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0.5f, \
							  .m21 = 0, .m22 = 0, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define SCALE_Y_U (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0, \
								.m21 = 0, .m22 = 0.5f, .m23 = 0, .m24 = 0, \
								.m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
								.m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define SCALE_Y_D (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0.5f, \
								.m21 = 0, .m22 = -0.5f, .m23 = 0, .m24 = 0, \
								.m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
								.m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define ROT_X_U (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0.5f, \
							  .m21 = 0, .m22 = -0.5f, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

#define ROT_X_D (t_matrix4x4){.m11 = 0, .m12 = 0, .m13 = 0, .m14 = 0.5f, \
	  						  .m21 = 0, .m22 = -0.5f, .m23 = 0, .m24 = 0, \
							  .m31 = 0, .m32 = 0, .m33 = 0, .m34 = 0, \
							  .m41 = 0, .m42 = 0, .m43 = 0, .m44 = 0};

void				key_listener(int keycodem t_conf *conf)
{
	if (keycode == 53) exit(EXIT_SUCCESS);
	if (keycode == 69) scale(SCALE_U, ((*(conf)))->obj);
	if (keycode == 78) scale(SCALE_D, ((*(conf)))->obj);
	if (keycode == 116) scale(SCALE_Y_U, ((*(conf)))->obj);
	if (keycode == 121) scale(SCALE_Y_D, ((*(conf)))->obj);
	if (keycode == 126) translation(TRANS_U, ((*(conf)))->obj);
	if (keycode == 125) translation(TRANS_D, ((*(conf)))->obj);
	if (keycode == 123) translation(TRANS_L, ((*(conf)))->obj);
	if (keycode == 124) translation(TRANS_R, ((*(conf)))->obj);
}

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
