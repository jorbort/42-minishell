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
