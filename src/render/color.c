/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 06:03:03 by toespino          #+#    #+#             */
/*   Updated: 2026/10/27 06:05:08 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color	color_incident(t_color base, t_color to_add, double r, double bright)
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

t_color	color_cap(t_nc to_cap)
{
	t_color	res;

	res.r = (uint8_t) ft_min(255, to_cap.r);
	res.g = (uint8_t) ft_min(255, to_cap.g);
	res.b = (uint8_t) ft_min(255, to_cap.b);
	return (res);
}
