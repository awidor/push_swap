/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:40:31 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:36 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_cnt(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c, size_t *pos)
{
	size_t	len;

	len = 0;
	while (s[*pos + len] != '\0' && s[*pos + len] != c)
		len++;
	return (len);
}

static char	*get_word(char const *s, char c, size_t *pos)
{
	char	*word;
	size_t	i;
	size_t	len;

	i = 0;
	while (s[*pos] != '\0' && s[*pos] == c)
		(*pos)++;
	len = word_len(s, c, pos);
	word = ft_calloc(len + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[*pos + i];
		i++;
	}
	*pos = *pos + len;
	return (word);
}

static void	free_everything(char **result, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	pos;
	char	**result;

	i = 0;
	pos = 0;
	if (s == NULL)
		return (NULL);
	result = ft_calloc(word_cnt(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < word_cnt(s, c))
	{
		result[i] = get_word(s, c, &pos);
		if (result[i] == NULL)
		{
			free_everything(result, i);
			return (NULL);
		}
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	string[] = "HelloaWorld";
// 	char	**result;

// 	result = ft_split(string, 'a');
// 	printf("%s", result[0]);
// 	free(result);
// }