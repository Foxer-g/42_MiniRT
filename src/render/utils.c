/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/11/20 11:18:18 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	ff_free(void *input)
{
	free(input);
	return (false);
}

void	create_img(t_data *scene)
{
	int64_t	i;
	int64_t	j;

	i = 0;
	while (i < scene->height)
	{
		j = 0;
		while (j < scene->width)
		{
			mlx_set_image_pixel(scene->mlx->mlx, scene->mlx->img,
				j, i, scene->img_c[i * scene->width + j]);
			j++;
		}
		i++;
	}
}

int64_t	get_ray_target(t_vector ray, t_data *scene, double *distance)//les donnee on ete recast
{
	double	closest;
	double	res;
	int64_t	i;
	int64_t	index;

	closest = DBL_MAX;
	i = -1 ;
	index = -1;
	while (((void **)scene->objs)[++i])
	{
		res = -1.0;
		// if (((t_plane *)scene->objs)[i].type == OBJ_SPHERE)
		if (((t_plane *)((void **)scene->objs)[i])->type == OBJ_SPHERE)
		{
			//res = sphere_distance((t_vector){0}, ray, ((t_sphere *)scene->objs)[i]);
			res = sphere_distance((t_vector){0}, ray, *(t_sphere *)((void **)scene->objs)[i]);
		}
		// else if (((t_plane *)scene->objs)[i].type == OBJ_CYLINDER)
		else if (((t_plane *)((void **)scene->objs)[i])->type == OBJ_CYLINDER)
		{
			// res = cylinder_distance((t_vector){0}, ray, ((t_cylinder *)scene->objs)[i]);
			res = cylinder_distance((t_vector){0} ,ray, *(t_cylinder *)((void **)scene->objs)[i]);
		}
		// else if (((t_plane *)scene->objs)[i].type == OBJ_PLANE)
		else if (((t_plane *)((void **)scene->objs)[i])->type == OBJ_PLANE)
		{
			//res = plane_distance((t_vector){0}, ray, ((t_plane *)scene->objs)[i]);
			res = plane_distance((t_vector){0}, ray, *(t_plane *)((void **)scene->objs)[i]);
		}
		if (res > 0.0 && res < closest)
		{
			closest = res;
			index = i;
		}
	}
	*distance = closest;
	return (index);

	/* read me
	
	((t_plane *)scene->objs)[i]):
	convertie directement data->objs en t_plane* 
	se qui revien a convertire objs en tableaux de structure t_plane, puis tu accede a la structure i.
	Tu accede a un tablaux de de structure alors que data->objs et une liste de 
	pointeur qui redirige chacun vers une structure
	
	*(t_plane *)((void **)scene->objs)[i]:
	commence par considerer data->objs comme tableaux de poiteur void 
	puis il recupere le poiteur numero i et le converti vers la structure desirer
	en le dereferencent j'obtien un t_plane et non plus un pointeur vers celui-ci
	t_plane pour les comparaison car ces la structure la plus petit et donc pas de depasement de memoire

	((t_plane *)scene->objs)[i].type = 
	(*(t_plane *)((void **)scene->objs)[i])->type =


	((void **)scene->objs)[++i] fonctionne car la fonction 
	ft_init_array_back et ft_extend_array_back en conjonction avec ad_data_scene_objects
	fournise a tableaux initial de (ARR_DEFAULT_SIZE(129) * type" element mis a null et qui s'auto remplit avec ad_data_ascene_objects
	et quit ariver au dernier null vien realoue une tableaux de (2 * ARR_DEFAULT_SIZE * type) luis aussi toujour null terminate
	*/
}




// static bool	intersect_ray(t_vector origin, t_vector ray, uint64_t index, t_data *scene) //current version
// {
// 	uint64_t	i;
// 	double		t;

// 	i = 0;
// 	while (((t_plane *)scene->objs)[i].type)
// 	{
// 		t = -1.0;
// 		if (i != index && ((t_plane *)scene->objs)[i].type == OBJ_SPHERE)
// 			t = sphere_distance(origin, ray, ((t_sphere *)scene->objs)[i]);
// 		else if (i != index && ((t_plane *)scene->objs)[i].type == OBJ_CYLINDER)
// 			t = cylinder_distance(origin, ray, ((t_cylinder *)scene->objs)[i]);
// 		else if (i != index && ((t_plane *)scene->objs)[i].type == OBJ_PLANE)
// 			t = plane_distance(origin, ray, ((t_plane *)scene->objs)[i]);
// 		if (t > 0.000001 && t < 1.0)
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

static bool	intersect_ray(t_vector origin, t_vector ray, uint64_t index, t_data *scene)//les donne on ete re cast
{
	uint64_t	i;
	double		t;

	i = 0;
	while (((void **)scene->objs)[i])
	{
		t = -1.0;
		//if (i != index && ((t_plane *)scene->objs)[i].type == OBJ_SPHERE)
		if (i != index && ((t_plane *)((void **)scene->objs)[i])->type == OBJ_SPHERE)
		{
			//t = sphere_distance(origin, ray, ((t_sphere *)scene->objs)[i]);
			t = sphere_distance(origin, ray, *(t_sphere *)((void **)scene->objs)[i] );
		}
		//else if (i != index && ((t_plane *)scene->objs)[i].type == OBJ_CYLINDER)
		else if (i != index && ((t_plane *)((void **)scene->objs)[i])->type == OBJ_CYLINDER)

		{
			//t = cylinder_distance(origin, ray, ((t_cylinder *)scene->objs)[i]);
			t = cylinder_distance(origin, ray, *(t_cylinder *)((void **)scene->objs)[i]);
		}
		//else if (i != index && ((t_plane *)scene->objs)[i].type == OBJ_PLANE)
		else if (i != index && ((t_plane *)((void **)scene->objs)[i])->type == OBJ_PLANE)
		{
			//t = plane_distance(origin, ray, ((t_plane *)scene->objs)[i]);
			t = plane_distance(origin, ray, *(t_plane *)((void **)scene->objs)[i]);
		}
		if (t > 0.000001 && t < 1.0)
			return (true);
		i++;
	}
	return (false);
}

t_nc	get_color(t_vector point, t_data *scene, uint64_t index, t_vector normal)
{
	double		incidence;
	double		denom;
	t_vector	light_ray;
	mlx_color	new_color;
	t_nc		res;

	res = (t_nc){0};
	light_ray = vector_sub(scene->lights.coordinate, point);
	incidence = vector_dot(normal, light_ray);
	if (incidence <= 0.0 || intersect_ray(point, light_ray, index, scene))
		return (res);
	denom = sqrt(vector_dot(normal, normal)
			* vector_dot(light_ray, light_ray));
	if (denom == 0.0)
		return (res);
	incidence /= denom;
	new_color = color_incident(((t_plane *)scene->objs)[index].color,
			scene->lights.color, incidence, scene->lights.brightness);
	light_add(&res, new_color);
	return (res);
}
