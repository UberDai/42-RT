/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:09 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "util.h"
#include "libft.h"

static char	*get_file_content(const char *filepath)
{
	FILE		*file;
	char		*content;
	size_t		size;
	size_t		ret;

	file = fopen(filepath, "r");

	if (file == NULL)
		die("Error: Failed to open the scene file.");

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);

	if (size == 0)
		die("Error: The scene file is empty.");

	content = malloc(sizeof(char) * size);
	ret = fread(content, sizeof(char), size, file);

	if (ret == 0)
		die("Error: An error occured while reading the file.");

	return (content);
}

static char	***parse_file(const char *content)
{
	char	**lines;
	char	***tokens;
	size_t	i;

	lines = ft_strsplit(content, '\n');

	tokens = malloc(sizeof(char**) * ft_splits_count(lines) + 1);

	i = 0;
	while (lines[i] != NULL)
	{
		tokens[i] = ft_strsplit(lines[i], '\t');
		free(lines[i]);
		++i;
	}

	tokens[i] = NULL;

	free(lines);

	return (tokens);
}

t_scene		*parse_scene_file(const char *filepath)
{
	char	*content;
	char	***tokens;

	content = get_file_content(filepath);
	tokens = parse_file(content);

	while (*tokens != NULL)
	{
		while (**tokens != NULL)
		{
			printf("%s | ", **tokens);
			++*tokens;
		}
		printf("\n");
		++tokens;
	}

	return (NULL);
}
