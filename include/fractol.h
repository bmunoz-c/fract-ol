/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:36 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 17:42:15 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# define WIDTH 800
# define HEIGHT 600

# define ERROR_1	"\n\t\tINVALID INPUT\n"
# define ERROR_2	"\n\tParameters:\n\t"
# define ERROR_3	"Option(1): Mandelbrot\n\t"
# define ERROR_4	"Option(2): Julia <param 2> <param 3>\n\t" 
# define ERROR_5	"Option(3): Burningship\n\n"
# define ERROR_6	"\tJulia's param range: < -2 <= X <= 2 >  < -2 ≤ Y ≤ 2 >\n"
# define ERROR_7	"\t\t___( MAX of 6 decimals )___\n\n"
# define MLX_ERROR	1
# define EXIT_FAILURE 1

# define NEON_BLUE			0x00BFFF
# define NEON_ORANGE		0xFF6600
# define LAVA_RED			0xFF3300 
# define PSYCHEDELIC_PURPLE	0x660066
# define MAGENTA_BURST		0xFF00FF
# define LIME_SHOCK			0xCCFF00

# define ESC				XK_Escape
# define ARROW_LEFT			XK_Left
# define ARROW_RIGHT		XK_Right
# define ARROW_DOWN			XK_Up
# define ARROW_UP			XK_Down
# define SCROLLUP			4
# define SCROLLDOWN			5
# define SHIFT				XK_Shift_L
# define TAB				XK_Tab

typedef struct _complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_fractal
{
	//_____MLX_____//
	void		*mlx_ptr;
	void		*win_ptr;
	//_____Image_____//
	t_img		img;
	//_____Hooks_____//
	int			type;
	t_complex	shift;
	t_complex	c;
	t_complex	z;
	int			color;
	double		zoom;
	double		max_re;
	double		max_im;
	double		min_re;
	double		min_im;
	double		iter_definition;
	double		limit;
}				t_fractal;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

//_____SOURCES_____//
//_____Check arguments_____//
int			check_dbl_format(char *xy);
int			check_ifdecimals(char *xy_checker);
int			check_max_min_dbl(char *xy);
int			check_julia_args(char *str);
void		check_args(int ac, char **av, t_fractal *fractal);

//_____Init fractal_____//
void		ft_terminate(t_fractal *fractal);
void		start_mlx(t_fractal *fractal);
void		start_img(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		init(t_fractal *fractol);

//_____Render / Fractal creation_____//
t_complex	sum_complex(t_complex z, t_complex c);
void		my_put_pixel(int x, int y, int color, t_fractal *fractal);
int			img_mandelbrot(t_fractal *fractal, t_complex c);
int			img_julia(t_fractal *fractal, t_complex z);
void		render_fractal(t_fractal *fractal);

//_____Events_____//
int			manage_key(int keycode, t_fractal *fractal);
int			mouse_hook(int keycode, int x, int y, t_fractal *fractal);
int			close_red_cross(t_fractal *fractal);

//_____Utils_____//
void		assign_type(char *str, t_fractal *f);
void		assign_ex_julia(t_fractal *f);
double		ft_atod(const char *str, double res, double decimal, int i);
int			color(int color, int i);

//_____Bonus_____//
t_complex	sum_complex_burningship(t_complex z, t_complex c);
int			img_burningship(t_fractal *fractal, t_complex c);

//_____Error message_____//
void		error_exit(void);
void		ft_error(void);

//_____Main Function_____//
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
int			main(int ac, char **av);

#endif
