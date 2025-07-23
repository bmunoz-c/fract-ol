/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:51 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 17:29:28 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//Kill window.
void	ft_terminate(t_fractal *fractal)
{
	if (fractal && fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
}

//Mlx ON.
void	start_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
	{
		ft_error();
		exit(MLX_ERROR);
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, "fractol");
	if (!fractal->win_ptr)
	{
		ft_error();
		ft_terminate(fractal);
		exit(MLX_ERROR);
	}
}

//Create image.
void	start_img(t_fractal *fractal)
{
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->win_ptr)
	{
		ft_error();
		ft_terminate(fractal);
		exit(MLX_ERROR);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.addr)
	{
		ft_error();
		ft_terminate(fractal);
		exit(MLX_ERROR);
	}
}

void	data_init(t_fractal *fractal)
{
	fractal->shift.x = 0.0;
	fractal->shift.y = 0.0;
	fractal->zoom = 1.0;
	fractal->max_re = 2;
	fractal->min_re = -2;
	fractal->max_im = 1.5;
	fractal->min_im = -1.5;
	fractal->iter_definition = 150;
	fractal->limit = 4.0;
	fractal->z.x = 0.0;
	fractal->z.y = 0.0;
	fractal->color = LIME_SHOCK;
}

void	init(t_fractal *fractal)
{
	start_mlx(fractal);
	start_img(fractal);
	data_init(fractal);
}
