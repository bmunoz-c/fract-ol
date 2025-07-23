/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:42 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 17:27:11 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	manage_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		exit(0);
	}
	if (keycode == ARROW_LEFT)
		fractal->shift.x -= 0.5 * fractal->zoom;
	if (keycode == ARROW_RIGHT)
		fractal->shift.x += 0.5 * fractal->zoom;
	else if (keycode == ARROW_UP)
		fractal->shift.y -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_DOWN)
		fractal->shift.y += 0.5 * fractal->zoom;
	else if (keycode == SHIFT)
		fractal->iter_definition += 10;
	else if (keycode == TAB)
		fractal->iter_definition -= 10;
	render_fractal(fractal);
	return (0);
}

void	mouse_position(t_fractal *fractal, double mouse_x, double mouse_y,
		double new_zoom)
{
	fractal->shift.x = mouse_x - ((mouse_x - fractal->shift.x)
			* (fractal->zoom / new_zoom));
	fractal->shift.y = mouse_y - ((mouse_y - fractal->shift.y)
			* (fractal->zoom / new_zoom));
	fractal->zoom = new_zoom;
}

void	move_image_zoom(t_fractal *fractal, double mouse_x, double mouse_y)
{
	if (fractal->shift.x > mouse_x)
		fractal->shift.x -= 0.2;
	else if (fractal->shift.x < mouse_x)
		fractal->shift.x += 0.2;
	if (fractal->shift.y < mouse_y)
		fractal->shift.y += 0.2;
	else if (fractal->shift.y > mouse_y)
		fractal->shift.y -= 0.2;
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	new_zoom;

	mouse_x = (x / (WIDTH / (fractal->max_re - fractal->min_re)))
		+ fractal->min_re;
	mouse_y = (y / (HEIGHT / (fractal->max_im - fractal->min_im)))
		+ fractal->min_im;
	move_image_zoom(fractal, mouse_x, mouse_y);
	if (keycode == SCROLLDOWN)
	{
		new_zoom = fractal->zoom * 0.9;
		mouse_position(fractal, mouse_x, mouse_y, new_zoom);
	}
	else if (keycode == SCROLLUP)
	{
		new_zoom = fractal->zoom * 1.1;
		mouse_position(fractal, mouse_x, mouse_y, new_zoom);
	}
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	render_fractal(fractal);
	return (0);
}

int	close_red_cross(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	exit(0);
	return (0);
}
/*
void	mouse_position(t_fractal *fractal, double mouse_x, double mouse_y,
		double new_zoom)
{
	fractal->shift.x = mouse_x - ((mouse_x - fractal->shift.x)
			* (fractal->zoom / new_zoom));
	fractal->shift.y = mouse_y - ((mouse_y - fractal->shift.y)
			* (fractal->zoom / new_zoom));
	fractal->zoom = new_zoom;
	printf("Mouse ZOOM: %f\n", fractal->zoom);
	printf("Mouse SHIFT: (%f, %f)\n", fractal->shift.x, fractal->shift.y);
}*/
