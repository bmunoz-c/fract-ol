/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:06:11 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 11:57:04 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}

void	my_put_pixel(int x, int y, int color, t_fractal *fractal)
{
	char	*pixels;

	pixels = fractal->img.addr + (y * fractal->img.line_len
			+ x * (fractal->img.bpp / 8));
	*(unsigned int *)pixels = color;
}

int	img_mandelbrot(t_fractal *fractal, t_complex c)
{
	t_complex	z;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i < fractal->iter_definition)
	{
		z = sum_complex(z, c);
		if (z.x * z.x + z.y * z.y > fractal->limit)
			return (i);
		i++;
	}
	return (i);
}

int	img_julia(t_fractal *fractal, t_complex z)
{
	int	i;

	i = 0;
	while (i < fractal->iter_definition)
	{
		z = sum_complex(z, fractal->c);
		if (z.x * z.x + z.y * z.y > fractal->limit)
			return (i);
		i++;
	}
	return (i);
}

void	render_fractal(t_fractal *fractal)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;

	y = -1;
	while (++y < HEIGHT)
	{
		c.y = (map(y, -1.5, 1.5, HEIGHT) * fractal->zoom) + fractal->shift.y;
		x = 0;
		while (x < WIDTH)
		{
			c.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift.x;
			if (fractal->type == 1)
				i = img_mandelbrot(fractal, c);
			else if (fractal->type == 2)
				i = img_julia(fractal, c);
			else if (fractal->type == 3)
				i = img_burningship(fractal, c);
			my_put_pixel(x, y, color(fractal->color, i), fractal);
			x++;
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
}
