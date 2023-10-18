
#include <minishell.h>

static char		*ft_pipestrdupli(const char *s1, char cut);
static int		ft_pipecntwrds(char const *s, char c);
static char		**ft_pipesplipri(char **split, char const *s, char c);
static char		**check_pipesplitter(char **split);

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
	split = check_pipesplitter(split);
	return (split);
}

static char	**ft_pipesplipri(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		words;

	words = 1;
	i = -1;
	j = 0;
	while (i++ < (int)ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			words = 1;
		else if ((words == 1 && s[i] != (unsigned char)c) || (s[i] == 124 || s[i] == 60 || s[i] == 6 || s[i] == 34 || s[i] == 39))
		{
			split[j] = ft_pipestrdupli(&s[i], c);
			if (split[j] == NULL)
				return (ft_freesp(split));
			words = 0;
			if (s[i] == 124 || s[i] == 60 || s[i] == 62 || s[i] == 34 || s[i] == 39)
				words = 1;
			j++;
		}
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
        if (s[i] != c && s[i] != 124 && s[i] != 60 && s[i] != 62 && s[i] != 34 && s[i] != 39)
            contl++;
        if ((s[i] == c || s[i] == 124 || s[i] == 60 || s[i] == 62 || s[i] == 34 || s[i] == 39) && contl > 0)
        {
            contw++;
            contl = 0;
        }
        if ((s[i] == 124 || s[i] == 60 || s[i] == 62 || s[i] == 34 || s[i] == 39) && contl == 0)
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
    if (str[i] == 124 || str[i] == 60 || str[i] == 62 || str[i] == 34 || str[i] == 39)
      i++;
    else
    {
      while ((str[i] != cut && str[i] != 0 && str[i] != 124 && str[i] != 60 && str[i] != 62 && str[i] != 34 && str[i] != 39))
        i++;
    }
    dupstr = malloc(i * sizeof(char) + 1);
    if (!dupstr)
        return (NULL);
    while (j < i)
    {
        dupstr[j] = str[j];
        j++;
    }
    dupstr[j] = 0;
    return (dupstr);
}

static char		**check_pipesplitter(char **split)
{
	int i;
	int quote;

	i = 0;
	quote = 0;
	while (split[i])
	{
		if (ft_strchr(split[i], 34) || ft_strchr(split[i], 34)) 
			quote = (int)split[i][0];
		if (quote > 0)
			break;
	i++;
	}
	while (quote > 0 && split[i])
	{
		if (ft_strchr(split[i + 1], quote) == NULL)
			split[i] = ft_strjoin_free(split[i + 1], split[i]);
	i++;
	}
	return (split);
}

