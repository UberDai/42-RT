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
#include <ftlst.h>

#include "parser.h"
#include "util.h"
#include "libft.h"

parsing_route_t		parsing_routes_g[] = {
	{ "scene", parse_scene },
	{ "sphere", parse_sphere },
	{ NULL, NULL }
};

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

static unsigned			count_options(char **lines)
{
	unsigned	i;

	i = 0;

	while (lines[i] && lines[i][0] == '\t')
		++i;

	return (i);
}

static parsing_sect_t	*parse_section(char ** lines, size_t *index)
{
	parsing_sect_t	*section;
	char			**tokens;
	unsigned		option_count;
	unsigned		i;
	
	section = NEW(parsing_sect_t);

	tokens = ft_strsplit(lines[*index], '\t');

	if (ft_splits_count(tokens) != 2)
		die("Invalid scene file.");

	section->type = ft_strdup(tokens[0]);
	section->name = ft_strdup(tokens[1]);

	++*index;

	option_count = count_options(lines + *index);
	section->options = malloc(sizeof(char**) * (option_count + 1));

	i = 0;
	while (lines[*index] && lines[*index][0] == '\t')
	{
		section->options[i] = ft_strsplit(lines[*index], '\t');
		++i;
		++*index;
	}

	section->options[i] = NULL;

	return (section);
}

static t_lst	*parse_file(const char *content)
{
	char			**lines;
	size_t			i;
	t_lst			*sections;
	parsing_sect_t	*section;

	sections = new_lst();

	lines = ft_strsplit(content, '\n');

	i = 0;
	while (lines[i] != NULL)
	{
		section = parse_section(lines, &i);
		lst_push_back(sections, section);
	}

	free(lines);

	return (sections);
}

static void	redirect_parsing(char ** tokens)
{
	size_t			i;
	parsing_route_t	*route;
	char			*error_message;

	i = 0;

	while (parsing_routes_g[i].name != NULL)
	{
		route = &parsing_routes_g[i];

		if (ft_strequ(route->name, tokens[0]))
		{
			route->parser(tokens);
			return ;
		}

		++i;
	}

	error_message = NULL;
	asprintf(&error_message, "Unknown keyword \"%s\".", tokens[0]);
	die(error_message);
}

static void	print_sections(t_lst *sections)
{
	t_lstiter		it;
	parsing_sect_t	*section;
	unsigned		i;
	unsigned		j;

	init_iter(&it, sections, increasing);

	while (lst_iterator_next(&it))
	{
		section = (parsing_sect_t*)it.data;

		printf("[%s] %s\n", section->type, section->name);

		i = 0;

		while (section->options[i] != NULL)
		{
			j = 0;

			while (section->options[i][j] != NULL)
			{
				if (j != 0)
					printf(", ");
				else
					printf("   ");

				printf("%s", section->options[i][j]);
				++j;
			}
			printf("\n");
			++i;
		}
		printf("\n");
	}
}

t_scene		*parse_scene_file(const char *filepath)
{
	char	*content;
	t_lst	*sections;
	size_t	i;

	content = get_file_content(filepath);
	sections = parse_file(content);

	print_sections(sections);

	i = 0;

	// while (0 && tokens[i] != NULL)
	{
		(void)redirect_parsing;
		++i;
	}

	// while (*tokens != NULL)
	// {
	// 	while (**tokens != NULL)
	// 	{
	// 		printf("%s | ", **tokens);
	// 		++*tokens;
	// 	}
	// 	printf("\n");
	// 	++tokens;
	// }

	return (NULL);
}
