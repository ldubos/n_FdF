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

void				translation(t_matrix4x4 matrix, t_obj *obj)
{

	t_obj			*tmp;

	tmp = obj;
	while (tmp != NULL)
	{
    	tmp->c_vertex.x += matrix.m14;
    	tmp->c_vertex.y += matrix.m24;
    	tmp->c_vertex.z += matrix.m34;
		tmp = tmp->next;
	}
}

void				scale(t_matrix4x4 matrix, t_obj *obj)
{
	t_obj			*tmp;

	tmp = obj;
	while (tmp != NULL)
	{
    	tmp->c_vertex.x *= matrix.m11;
    	tmp->c_vertex.y *= matrix.m22;
    	tmp->c_vertex.z *= matrix.m33;
		tmp = tmp->next;
	}
}

void				rot_x(/*t_matrix4x4 matrix, */t_obj *obj, int angl)
{
	t_obj			*tmp;

	tmp = obj;
	while (tmp != NULL)
	{
/*    	tmp->c_vertex.x += matrix.m11;
    	tmp->c_vertex.y += cos(matrix.m22) - sin(matrix.m23);
    	tmp->c_vertex.z += sin(matrix.m32) + cos(matrix.m33);
		tmp = tmp->next;*/
		tmp->c_vertex.x += tmp->c_vertex.x;
		tmp->c_vertex.y += cos(angl) - sin(angl);
		tmp->c_vertex.z += sin(angl) + cos(angl);
		tmp = tmp->next;
	}
}

void				rot_y(/*t_matrix4x4 matrix, */t_obj *obj, int angl)
{
	t_obj			*tmp;

	tmp = obj;
	while (tmp != NULL)
	{
/*    	tmp->c_vertex.x += cos(matrix.m11) + sin(matrix.m13);
    	tmp->c_vertex.y += matrix.m22;
    	tmp->c_vertex.z += -sin(matrix.m31) + cos(matrix.m33);
		tmp = tmp->next;*/
		tmp->c_vertex.x += cos(angl) + sin(angl);
		tmp->c_vertex.y += tmp->c_vertex.y;
		tmp->c_vertex.z += -sin(angl) + cos(angl);
		tmp = tmp->next;
	}
}

void				rot_z(/*t_matrix4x4 matrix, */t_obj *obj, int angl)
{
	t_obj			*tmp;

	tmp = obj;
	while (tmp != NULL)
	{
/*    	tmp->c_vertex.x += cos(matrix.m11) - sin(matrix.m12);
    	tmp->c_vertex.y += sin(matrix.m21) + cos(matrix.m22);
    	tmp->c_vertex.z += matrix.m33;
		tmp = tmp->next;*/
		tmp->c_vertex.x += cos(angl) - sin(angl);
		tmp->c_vertex.y += sin(angl) + cos(angl);
		tmp->c_vertex.z += tmp->c_vertex.z;
		tmp = tmp->next;
	}
}
