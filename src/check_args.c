/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:26 by ctacconi          #+#    #+#             */
/*   Updated: 2024/07/31 11:56:22 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_double_format(char *xy)
{
	int	i;

	i = 0;
	if (xy[i] == '\0')
		return (0);
	if (xy[0] == '-' && !ft_isdigit(xy[1]))
		return (0);
	if (xy[0] == '-')
	{
		if (xy[2] && xy[2] != '.')
			return (0);
		i++;
	}
	if (xy[i + 1] && xy[i + 1] == '.')
	{
		i += 2;
		while (xy[i])
		{
			if (!ft_isdigit(xy[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_if_decimals(char *xy_check)
{
	if (*xy_check == '2' && *(xy_check + 1) == '.')
	{
		xy_check += 2;
		if (ft_strlen(xy_check) > 6)
			return (0);
		while (*xy_check)
		{
			if (*xy_check != '0')
				return (0);
			xy_check++;
		}
		return (1);
	}
	if (*(xy_check + 1) && *(xy_check + 1) == '.')
	{
		xy_check += 2;
		if (ft_strlen(xy_check) > 6)
			return (0);
	}
	return (1);
}

int	check_max_min_double(char *xy)
{
	char	*xy_check;

	xy_check = xy;
	if (xy_check[0] == '-')
		xy_check++;
	if (*xy_check > '2')
		return (0);
	if (*(xy_check + 1) && *(xy_check + 1) != '.')
		return (0);
	if (!check_if_decimals(xy_check))
		return (0);
	return (1);
}

int	check_julia_args(char *str)
{
	if (!check_double_format(str))
		return (0);
	if (!check_max_min_double(str))
		return (0);
	return (1);
}

void	check_args(int ac, char **av, t_fractal *fractal)
{
	int	i;

	i = -1;
	while (av[1][++i])
		av[1][i] = ft_tolower(av[1][i]);
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		|| (ac == 2 && !ft_strncmp(av[1], "burningship", 12))
		|| (ac == 2 && !ft_strncmp(av[1], "julia", 6))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		assign_type(av[1], fractal);
		if (ac == 2 && !ft_strncmp(av[1], "julia", 6))
			assign_ex_julia(fractal);
		else if (ac == 4)
		{
			if (!check_julia_args(av[2]) || !check_julia_args(av[3]))
				error_exit();
			fractal->c.x = ft_atod(av[2], 0, 0, 0);
			fractal->c.y = ft_atod(av[3], 0, 0, 0);
		}
	}
	else
		error_exit();
}
