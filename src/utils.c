/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:06:21 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/30 18:39:07 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	assign_type(char *str, t_fractal *f)
{
	if (ft_strncmp(str, "mandelbrot", 10) == 0)
		f->type = 1;
	else if (ft_strncmp(str, "julia", 5) == 0)
		f->type = 2;
	else if (ft_strncmp(str, "burningship", 11) == 0)
		f->type = 3;
}

void	assign_ex_julia(t_fractal *f)
{
	f->c.x = -0.70176;
	f->c.y = 0.3842;
}

double	ft_atod(const char *str, double res, double decimal, int i)
{
	int	sign;
	int	j;

	sign = 1;
	j = -1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0');
		i++;
	}
	if (str[i++] == '.')
	{
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			decimal += (pow(10, j) * (str[i] - '0'));
			j--;
			i++;
		}
	}
	return ((res + decimal) * sign);
}

int	color(int color, int i)
{
	int	r;
	int	g;
	int	b;

	r = (sin(0.1 * i) + 1) * 127 + ((color >> 16) & 0xFF);
	g = (sin(0.2 * i) + 1) * 127 + ((color >> 8) & 0xFF);
	b = (sin(0.3 * i) + 1) * 127 + (color & 0xFF);
	return ((r << 16) | (g << 8) | b);
}
