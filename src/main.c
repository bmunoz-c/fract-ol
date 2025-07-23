/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:06:01 by ctacconi          #+#    #+#             */
/*   Updated: 2024/08/02 17:39:46 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_exit(void)
{
	write(2, &ERROR_1, ft_strlen(ERROR_1));
	write(2, &ERROR_2, ft_strlen(ERROR_2));
	write(2, &ERROR_3, ft_strlen(ERROR_3));
	write(2, &ERROR_4, ft_strlen(ERROR_4));
	write(2, &ERROR_5, ft_strlen(ERROR_5));
	write(2, &ERROR_6, ft_strlen(ERROR_6));
	write(2, &ERROR_7, ft_strlen(ERROR_7));
	exit (EXIT_FAILURE);
}

void	ft_error(void)
{
	write(2, "Memory allocation failure\n", 26);
}

//to rescale from 0...800 to -2...+2
double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (argc < 2)
		error_exit();
	check_args(argc, argv, &fract);
	init(&fract);
	render_fractal(&fract);
	mlx_hook(fract.win_ptr, ButtonPress, ButtonPressMask, mouse_hook, &fract);
	mlx_key_hook(fract.win_ptr, manage_key, &fract.mlx_ptr);
	mlx_hook(fract.win_ptr, ON_DESTROY, 0, close_red_cross, &fract);
	mlx_loop(fract.mlx_ptr);
	return (0);
}
