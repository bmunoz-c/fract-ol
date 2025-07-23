/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:36:39 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/08/02 17:27:46 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	sum_complex_burningship(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * fabs(z.x) * fabs(z.y) + c.y;
	return (result);
}

//Create Burningship fractal.
int	img_burningship(t_fractal *fractal, t_complex c)
{
	t_complex	z;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i < fractal->iter_definition)
	{
		z = sum_complex_burningship(z, c);
		if (z.x * z.x + z.y * z.y > fractal->limit)
			return (i);
		i++;
	}
	return (i);
}
