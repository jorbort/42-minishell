
#include <minishell.h>

static char		*ft_pipestrdupli(const char *s1);
static int		ft_pipecntwrds(char const *s);
static char		**ft_pipesplipri(char **split, char const *s);
//static char		**check_pipesplitter(char **split);

char	**ft_pipesplit(char const *s)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((ft_pipecntwrds(s) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_pipecntwrds(s) != 0)
	{
		if (ft_pipesplipri(split, s) == NULL)
			return (NULL);
	}
	else
		split[0] = NULL;
//	split = check_pipesplitter(split);
	return (split);
}

static int    ft_pipecntwrds(char const *s)
{
    int	i;
    int	contl;
    int	contw;
	int	flag;

    i = 0;
    contw = 0;
    contl = 0;
	flag = 0;
    while (s[i] != 0)
    {
		if (ft_isaquote(s[i]) && flag == 1)
			flag = 0;
        if (!ft_isspace(s[i]) && !ft_isapipe(s[i])) 
            contl++;
        if (((ft_isspace(s[i]) || ft_isapipe(s[i])) && contl > 0) && flag == 0)
        {
            contw++;
            contl = 0;
        }
		if ((ft_isapipe(s[i]) || ft_isaquote(s[i])) && flag == 0)
			contw++;
		if (ft_isaquote(s[i]))
			flag = 1;
        i++;
    }
    if (contl > 0)
        contw++;
	printf("%i", contw);
	return (contw);
}
static char	**ft_pipesplipri(char **split, char const *s)
{
	int		i;
	int		j;
	int		words;

	words = 1;
	i = -1;
	j = 0;
	while (i++ < (int)ft_strlen(s) - 1)
	{
		if (ft_isspace(s[i]))
			words = 1;
		else if ((words == 1 && !ft_isspace(s[i])) || ft_isapipe(s[i]) || ft_isaquote(s[i]))
		{
			split[j] = ft_pipestrdupli(&s[i]);
			if (split[j] == NULL)
				return (ft_freesp(split));
			words = 0;
			if (ft_isapipe(s[i]))
				words = 1;
		j++;
		}
	i++;
	}
	split[j] = NULL;
	return (split);
}

static    char    *ft_pipestrdupli(const char *s1)
{
    static int     i = 0;
    int            j;
    const char    *str;
    char        *dupstr;

    str = s1;
    j = 0;
    if (ft_isapipe(str[i]))
		i++;
    else
    {
      while (!ft_isspace(str[i]) && str[i] != 0 && !ft_isapipe(str[i]))
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
/*
static char		**check_pipesplitter(char **split)
{
	int i;
	int j;
	int quote;
	char *tmp;
	
	i = 0;
	while (split[i])
	{
		if ((ft_strchr(split[i], 39) || ft_strchr(split[i], 34)) && ft_strlen(split[i]) == 1) 
		{
			quote = (int)split[i][0];
			j = i + 1;
			while (split[j] && (!ft_strchr(split[j], quote)))
			{
				tmp = split[j];	
				split[i] = ft_strjoin_doublefree(split[i], split[j]);
				split[j] = tmp;				
				j++;
			}
			if (split[j] && (ft_strchr(split[j], 39) || ft_strchr(split[j], 34)))
				{
						split[i] = ft_strjoin_doublefree(split[i], split[j]);
						j++;
				}
			i++;
			while (split[j])
			{
				split[i] = split[j];
				
				i++;
				j++;
			}
			split[i] = NULL;
		}
		else
			i++;
	}
	return (split);
}
*/
