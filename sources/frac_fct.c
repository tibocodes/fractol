/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:52:55 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/18 18:52:01 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			in_loop(t_frac *frac, double x, double y)
{
	int a;
	int color;

	a = 0;
	while (a <= frac->amax && frac->z2 <= frac->k)
	{
		frac->rz2 = frac->rz;
		frac->rz = frac->rz * frac->rz - frac->iz * frac->iz + frac->rc;
		frac->iz = 2 * frac->rz2 * frac->iz + frac->ic;
		frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
		color = a / frac->amax * 0xFFFFFF;
		if (frac->z2 >= frac->k)
		{
			my_pixel_put_img(frac, x, y, color);
			// mlx_pixel_put(frac->mlx, frac->win, x, y, color);
		}
		a++;
	}
}

void			aff_frac_julia(void *frac2)
{
	double	x;
	double	y;
	t_frac	*frac;
	double	q;

	frac = (t_frac*)frac2;
	q = ft_abs((frac->xmax - frac->xmin) / (double)frac->size);
	x = 0;
	while (x < frac->size)
	{
		y = 0;
		while (y < frac->size)
		{
			frac->rz = (frac->xmin + (x) * q);
			frac->iz = (frac->ymin + (y) * q);
			frac->rc = frac->juliax;
			frac->ic = frac->juliay;
			frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
			in_loop(frac, x, y);
			y++;
		}
		x++;
	}
	mlx_clear_window(frac->mlx, frac->win);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}

void			aff_frac_mandel(void *frac2)
{
	double	x;
	double	y;
	t_frac	*frac;
	double	q;

	frac = (t_frac*)frac2;
	q = ft_abs((frac->xmax - frac->xmin) / (double)frac->size);
	x = 0;
	while (x < frac->size)
	{
		y = 0;
		while (y < frac->size)
		{
			frac->rz = (frac->xmin + (x) * q);
			frac->iz = (frac->ymin + (y) * q);
			frac->rc = frac->rz;
			frac->ic = frac->iz;
			frac->z2 = frac->rz * frac->rz + frac->iz * frac->iz;
			in_loop(frac, x, y);
			y++;
		}
		x++;
	}
	mlx_clear_window(frac->mlx, frac->win);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}
