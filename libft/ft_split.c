/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:37:34 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/17 11:17:52 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_charset(char c, char *charset)
{
	if (charset[0] == c)
		return (1);
	return (0);
}

static int		ft_count_word(const char *s, char *charset)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (is_charset(s[i], charset))
		{
			words++;
			while (is_charset(s[i], charset) && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

char			*ft_len_word(const char *s, char *charset)
{
	int		len;
	int		k;
	char	*word;

	len = 0;
	while (s[len] && !is_charset(s[len], charset))
		len++;
	if (!(word = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	k = 0;
	while (len > k)
	{
		word[k] = s[k];
		k++;
	}
	word[len] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;
	char	charset[1];

	charset[0] = c;
	if (!s || !(tab = malloc(sizeof(char *) * (ft_count_word(s, charset) + 2))))
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		if (is_charset(s[i], charset))
			while (s[i] != '\0' && is_charset(s[i], charset))
				i++;
		else
		{
			tab[k++] = ft_len_word(s + i, charset);
			while (s[i] != '\0' && !is_charset(s[i], charset))
				i++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
