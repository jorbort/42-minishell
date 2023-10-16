
#include <minishell.h>

static char		*ft_pipestrdupli(const char *s1, char cut);
static int		ft_pipecntwrds(char const *s, char c);
static char		**ft_pipesplipri(char **split, char const *s, char c);

char	**ft_pipesplit(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((ft_pipecntwrds(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_pipecntwrds(s, c) != 0)
	{
		if (ft_pipesplipri(split, s, c) == NULL)
			return (NULL);
	}
	else
		split[0] = NULL;
	return (split);
}

static char	**ft_pipesplipri(char **split, char const *s, char c)
{
	size_t	i;
	int		j;
	int		words;

	words = 1;
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			words = 1;
		else if ((words == 1 && s[i] != (unsigned char)c) ||
				(s[i] == 124 || s[i] == 60 || s[i] == 62))
		{
			split[j] = ft_pipestrdupli(&s[i], c);
			if (split[j] == NULL)
				return (ft_freesp(split));
			words = 0;
			j++;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

static int    ft_pipecntwrds(char const *s, char c)
{
    int    i;
    int    contl;
    int    contw;

    i = 0;
    contw = 0;
    contl = 0;
    while (s[i] != 0)
    {
        if (s[i] != c && s[i] != 124 && s[i] != 60 && s[i] != 62)
            contl++;
        if (s[i] == c && contl > 0)
        {
            contw++;
            contl = 0;
        }
        if (s[i] == 124 || s[i] == 60 || s[i] == 62)
          contw++;
        i++;
    }
    if (contl > 0)
        contw++;
    return (contw);
}

static    char    *ft_pipestrdupli(const char *s1, char cut)
{
    int            i;
    int            j;
    const char    *str;
    char        *dupstr;

    str = s1;
    j = 0;
    i = 0;
    if (str[i] == 124 || str[i] == 60 || str[i] == 62)
      i++;
    else
    {
      while ((str[i] != cut && str[i] != 0) || (str[i] != 124 && str[i] != 60 && str[i] == 62))
        i++;
    }
    dupstr = malloc(i * sizeof(char) + 1);
    if (!dupstr)
    {
        return (NULL);
    }
    while (j < i)
    {
        dupstr[j] = str[j];
        j++;
    }
    dupstr[j] = 0;
    return (dupstr);
}

