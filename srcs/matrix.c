/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:53:45 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 14:53:48 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void               translation(t_conf conf, t_vec3 *vertex)
{
    ((*(vertex))).x += conf.matrix.m14;
    ((*(vertex))).y += conf.matrix.m24;
    ((*(vertex))).z += conf.matrix.m34;
}

void               scale(t_conf conf, t_vec3 *vertex)
{
    ((*(vertex))).x *= conf.matrix.m11;
    ((*(vertex))).y *= conf.matrix.m22;
    ((*(vertex))).z *= conf.matrix.m33;
}

void               rot_x(t_conf conf, t_vec3 *vertex)
{
    ((*(vertex))).x += conf.matrix.m11;
    ((*(vertex))).y += cos(conf.matrix.m22) - sin(conf.matrix.m23);
    ((*(vertex))).z += sin(conf.matrix.m32) + cos(conf.matrix.m33);
}

void               rot_y(t_conf conf, t_vec3 *vertex)
{
    ((*(vertex))).x += cos(conf.matrix.m11) + sin(conf.matrix.m13);
    ((*(vertex))).y += conf.matrix.m22;
    ((*(vertex))).z += -sin(conf.matrix.m31) + cos(conf.matrix.m33);
}

void               rot_z(t_conf conf, t_vec3 *vertex)
{
    ((*(vertex))).x += cos(conf.matrix.m11) - sin(conf.matrix.m12);
    ((*(vertex))).y += sin(conf.matrix.m21) + cos(conf.matrix.m22);
    ((*(vertex))).z += conf.matrix.m33;
}
