/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/03/05 12:19:38 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int main(void)
{
	while (1)
	{
		char *line;
		char **list_path;
		char *line_pwd;
		line =readline("minishell> ");
		add_history(line);
		list_path = ft_split(getenv("PATH"), ':');
		line_pwd = getcwd(NULL, 0);
		if (!ft_strncmp(line, "pwd", 3))echo
			ft_printf("%s\n", line_pwd);
		""
		printf("%s\n", line);
	}
	
}*/

//char	*get_env_own(char **list_env, char *env_to) 


/*void execute_comm(char *comm, char *path)
{
	if (path == NULL)
	{
		char **list_path;
		list_path = ft_split(getenv("PATH"), ':');
		
		free (list_path);
	}
			
}


int main(int **argc, char **argv, char **envp)
{


	
}
*/





int put_flag(char c, int flag)
{
	if (flag == 0 && c == '"')
		return (1);
	else if (flag == 0 && c == '\'')
		return (2);
	else if (flag == 1 && c == '"')
		return (0);
	else if (flag == 2 && c == '\'')
		return (0);
	else 
		return (flag);
}

/*
int	count_word(char const *str, char c)
{
	int	i;
	int	count;
	int flag;

	flag = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	
	while (str[i] != '\0')
	{
		flag = put_flag(str[i], flag);
		while (str[i] != '\0' && str[i] != c && flag == 0)
		{
			i++;
			flag = put_flag (str[i], flag);
		}
		
		if ((str[i] == '\0' || str[i] == c )&& flag == 0)
			count++;
		while (str[i] != '\0' && str[i] == c && flag == 0 )
		{
			i++;
			flag = put_flag(str[i], flag);
		}
		if (flag == 1 || flag == 2)
			i++;
	}
	return (count);
}*/
 int count_len(char *str)
 {	
	int i = 0;
	int count  = 0;
	int flag = 0;
	int flag1 = 0;
	while (str[i] != '\0')
	{
		flag1 = put_flag(str[i], flag);
		//printf("flag = %d et flag1 = %d\n", flag, flag1);
		if ((flag1 == 1 && flag !=1)|| (flag1 == 2 && flag !=2) || (flag1 == 0 && flag!= 0))
			i++;
		else
			{
				printf("%c", str[i]);
				count++;
				i++;
				
			}
		flag = flag1;
		
	}
	printf("\n");
	return (count);
	
 }




int main ()
{
	while (1)
	{
		
		//char **tab;
		char *line;
		line =readline("minishell> ");
		add_history(line);
		printf("len word : %d\n", count_len(line));
		/*tab = ft_split(line, ' ');
		int i = 0;
		while(tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}*/
	}	
}