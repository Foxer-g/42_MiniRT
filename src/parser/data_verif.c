/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:13:45 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/23 19:57:09 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


// char	*is_identifier(char *word, int fd)
// {
// 	int		i;
// 	char	*flag;

// 	i = 0;
// 	if ((!ft_strncmp(word, "A", 1) && ft_isspace(word[1])) ||
// 		(!ft_strncmp(word, "C", 1) && ft_isspace(word[1])) ||
// 		(!ft_strncmp(word, "L", 1) && ft_isspace(word[1])) ||
// 		(!ft_strncmp(word, "sp", 2) && ft_isspace(word[2])) ||
// 		(!ft_strncmp(word, "pl", 2) && ft_isspace(word[2])) ||
// 		(!ft_strncmp(word, "cy", 2) && ft_isspace(word[2])))
// 		return (NULL);
// 	while (word[i] && !ft_isspace(word[i]))
// 		i++;
// 	flag = ft_substr(word, 0, i);
// 	if (!flag)
// 		malloc_error(EXIT_FAILURE, fd);
// 	return (flag);
// }

char	*is_identifier(char *word, int fd)
{
	int		i;
	char	*flag;

	i = 0;
	while (word[i] && !ft_isspace(word[i]))
		i++;
	flag = ft_substr(word, 0, i);
	if (!flag)
		malloc_error(EXIT_FAILURE, fd);
	if (!ft_strncmp(flag, "A", 2) || !ft_strncmp(flag, "C", 2) ||
		!ft_strncmp(flag, "L", 2) || !ft_strncmp(flag, "sp", 3) ||
        !ft_strncmp(flag, "pl", 3) || !ft_strncmp(flag, "cy", 3))
	{
		free(flag);
		return (NULL);
	}
	return (flag);
}
