/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:00:50 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:42 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start_idx;
	size_t	end_idx;
	size_t	i;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_idx = 0;
	end_idx = ft_strlen(s1) - 1;
	while (s1[start_idx] != '\0' && is_set(s1[start_idx], set) == 1)
		start_idx++;
	if (s1[start_idx] == '\0')
		return (ft_strdup(""));
	while (end_idx > start_idx && is_set(s1[end_idx], set) == 1)
		end_idx--;
	result = malloc((end_idx - start_idx + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start_idx <= end_idx)
		result[i++] = s1[start_idx++];
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char string[] = "s";
// 	char set[] = "";
// 	char *trimmed = ft_strtrim(string, set);
// 	printf("%s\n", trimmed);
// 	free(trimmed);
// 	return (0);
// }