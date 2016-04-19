/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:24:02 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 19:12:48 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void	aff_frac(t_frac *frac)
{
	double	x;
	double	y;
	int		a;

//printf("aff_frac %f %f %f %f %f\n", frac->zoom, frac->xmin, frac->xmax, frac->ymin, frac->ymax);
	
	x = 0;
	while (x < frac->size)
	{
		y = 0;
		while (y < frac->size)
		{
			frac->rz = (frac->xmin + (x - frac->offx) * (frac->xmax - frac->xmin)
				/ frac->size) * frac->zoom;
			frac->iz = (frac->ymin + (y - frac->offy) * (frac->ymax - frac->ymin)
				/ frac->size) * frac->zoom;
			//ensemble de mandelbrot
			//rc = rz;
			//ic = iz;
			//ensemble de julia
			frac->rc = 0.285;
			frac->ic = 0.01;
			frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
			a = 0;
			while (a <= frac->amax && frac->z2 <= frac->k)
			{
				frac->rz2 = frac->rz;
				frac->rz = frac->rz * frac->rz - frac->iz * frac->iz + frac->rc;
				frac->iz = 2 * frac->rz2 * frac->iz + frac->ic;
				frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
				if (frac->z2 >= frac->k)
					mlx_pixel_put(frac->mlx, frac->win, x, y, a / frac->amax * 0xFFFFFF);
				a++;
			}
			if (a == frac->amax)
					mlx_pixel_put(frac->mlx, frac->win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void		frac_display(char *str)
{
	t_frac *frac;

	frac = frac_init(str, 0 , 0);
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, frac->size, frac->size, "fractol");
	aff_frac(frac);
	mlx_key_hook(frac->win, my_key_funct, frac);
	mlx_mouse_hook(frac->win, my_mouse_funct, frac);
	mlx_loop(frac->mlx);
}
