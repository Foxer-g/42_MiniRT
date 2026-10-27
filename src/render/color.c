/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 06:03:03 by toespino          #+#    #+#             */
/*   Updated: 2026/10/26 10:04:34 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color	color_ratio(t_color color, double ratio)
{
	t_color	res;

	res.r = (uint8_t) (color.r * ratio);
	res.g = (uint8_t) (color.g * ratio);
	res.b = (uint8_t) (color.b * ratio);
	return (res);
}

t_color	color_incident(t_color base, t_color to_add, double ratio, double bright)
{
	t_color	res;

	res.r = base.r * (to_add.r / 255.0) * ratio * bright;
	res.g = base.g * (to_add.g / 255.0) * ratio * bright;
	res.b = base.b * (to_add.b / 255.0) * ratio * bright;

	return (res);
}

void	light_add(t_nc *base, t_color to_add)
{
	*base.r += (uint64_t) to_add.r;
	*base.g += (uint64_t) to_add.g;
	*base.b += (uint64_t) to_add.b;
}
