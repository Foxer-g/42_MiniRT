/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:13:45 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 13:51:45 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	identifier_selector(t_data *s, t_parse *p, int i)
{
	p->data_line = ft_substr(p->identifier, i, ft_strlen(p->identifier));
	if (!p->data_line)
		data_malloc_error(s, ERR_INIT_DATA_LINE);
	if (!ft_strncmp(p->identifier, "A", 2))	
		return ;	
		//fill_ambient_lighting(s, s->p);
	else if (!ft_strncmp(s->p->identifier, "C", 2))
		return ;
	// 	fill_camera_data(s, s->p));
	else if (!ft_strncmp(s->p->identifier, "L", 2))
		return ;
	// 	fill_light_data(s, s->p);
	else if (!ft_strncmp(s->p->identifier, "sp", 3))
		return ;
	// 	fill_sphere_data(s, s->p);
	else if (!ft_strncmp(s->p->identifier, "pl", 3))
		return ;
	// 	fill_plane_data(s, s->p);
	else if (!ft_strncmp(s->p->identifier, "cy", 3))
		return ;
	// 	fill_cylinder_data(s, s->p);
	else if (!ft_strncmp(s->p->identifier, "T", 2)) //a faire apres la manda
		return ;
	// 	fill_triangle_data(s, s->p);
	else if (1)
		p->err_type = 1;
	error_rt_selection(p);
}

bool	is_identifier(t_data *s)
{
	char	*new_identifier;
	int		i;

	i = 0;
	while (s->p->identifier[i] && !ft_isspace(s->p->identifier[i]))
		i++;
	new_identifier = ft_substr(s->p->identifier, 0, i);//ineficase
	if (!new_identifier)
		data_malloc_error(s, ERR_INIT_NIDENTIFIER);
	free(s->p->identifier);
	s->p->identifier = new_identifier;
	identifier_selector(s, s->p, i);
	return (s->p->error);
}
