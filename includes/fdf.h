#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include <stdio.h>

# include "libft.h"
# include "get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;

}				t_img;

typedef struct	s_vec3
{
	int			x;
	int			y;
	int			z;
}				t_vec3;

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

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
}				t_matrix4x4;

typedef struct	s_obj
{
	struct s_obj \
	*p_vertex;
	t_vec3		c_vertex;
	struct s_obj \
	*next;
}				t_obj;

typedef struct	s_conf
{
	t_env		env;
	t_img		img;
	t_matrix4x4	matrix;
	t_obj		*obj;
/*	t_vec2		offset; */
	t_vec2		pos;
	int			zoom;
	int			width;
	int			height;
}				t_conf;

/*
** error.c
*/

void				arg_error(int ac);
void				open_error();
void				gnl_error(int err);
void				malloc_error();

/*
** matrix.c
*/

void               translation(t_matrix4x4 matrix, t_obj *obj);
void               scale(t_matrix4x4 matrix, t_obj *obj);
void               rot_x(t_obj *obj, int angl);
void               rot_y(t_obj *obj, int angl);
void               rot_z(t_obj *obj, int angl);

/*
** obj.c
*/

void				read_obj(t_conf *conf, char *path);
t_vec2				orthographic(t_conf conf, t_vec3 vertex);

/*
** draw.c
*/

void				draw_obj(t_conf conf);

/*
** hook.c
*/

int					key_hook(int keycode, t_conf *conf);

#endif
