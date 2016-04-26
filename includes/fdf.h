#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_env t_env;
typedef struct	s_img t_img;
typedef struct	s_vec3 t_vec3;
typedef struct	s_vec2 t_vec2;
typedef struct	s_matrix4x4 t_matrix4x4;
typedef struct	s_obj t_obj;
typedef struct	s_conf t_conf;

/*
** Structs declaration
*/

typedef struct	s_env
{
	void		*mlx;
	void		*win;
};

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;

};

typedef struct	s_vec3
{
	int			x;
	int			y;
	int			z;
};

typedef struct	s_vec2
{
	int			x;
	int			y;
};

/*
**     Rotation    => M11, M12, M13,
**                    M21, M22, M23,
**                    M31, M32, M33
**
**     Scale       => M11, M22, M33
**
**     Translation => M14, M24, M34
**
** | X' |   | M11 M12 M13 M14 |   | X |
** |    |   |                 |   |   |
** | Y' |   | M21 M22 M23 M24 |   | Y |
** |    | = |                 | * |   |
** | Z' |   | M31 M32 M33 M34 |   | Z |
** |    |   |                 |   |   |
** | W' |   | M41 M42 M43 M44 |   | 1 | -> utility ?
*/
typedef struct	s_matrix4x4
{
	float		m11;
	float		m12;
	float		m13;
	float		m14;
	float		m21;
	float		m22;
	float		m23;
	float		m24;
	float		m31;
	float		m32;
	float		m33;
	float		m34;
	float		m41;
	float		m42;
	float		m43;
	float		m44;
};

typedef struct	s_obj
{
	t_obj		*p_vertex;
	t_vec3		c_vertex;
	t_obj		*next;
};

typedef struct	s_conf
{
	t_env		env;
	t_img		img;
	t_matrix4x4	matrix;
	t_obj		*obj;
	t_vec2		offset;
	t_vec2		pos;
	int			zoom;
	int			width;
	int			height;
};

/*
** error.c
*/

void				arg_error(int ac);
void				open_error();
void				gnl_error(int err);
void				malloc_error();

/*
** obj.c
*/

void				read_obj(t_conf *conf, char *path);

#endif
