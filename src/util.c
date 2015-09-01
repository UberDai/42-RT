/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:12:04 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/08 03:40:03 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		die(const char *message)
{
	ft_putendl(message);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
