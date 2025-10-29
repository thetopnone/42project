/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:49:31 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


//This function checks whether theres a built in being called
//and if it is, which one?
//          There should be checked only the first argument
t_built_in  ft_check_for_built_in(char *string, t_error *err)
{
    err->check_for_built_in = 0;
    if (!ft_strncmp(string, "cd", ft_strlen("cd")))
        return (B_CD);
    else if (!ft_strncmp(string, "echo", ft_strlen("echo")))
        return (B_ECHO);
    else if (!ft_strncmp(string, "env", ft_strlen("env")))
        return (B_ENV);
    else if (!ft_strncmp(string, "exit", ft_strlen("exit")))    // WE WILL NEED TO CHOOSE
        return (B_EXIT);
    else if (!ft_strncmp(string, "export", ft_strlen("export")))
        return (B_EXPORT);
    else if (!ft_strncmp(string, "pwd", ft_strlen("pwd")))
        return (B_PWD);
    else if (!ft_strncmp(string, "unset", ft_strlen("unset")))
        return (B_UNSET);
    else
        return (B_NONE);
    err->check_for_built_in = 1;
}

//          just a concept - function will be edited
void    ft_pick_built_in_to_exe(t_built_in built_in, t_cmd *command, t_error *err)
{
    if (built_in == B_CD)
        ft_cd(command->argv);
    else if (built_in == B_ECHO)
        ft_echo();
    else if (built_in == B_ENV)
        ft_env();
    else if (built_in == B_EXIT)
        ft_exit();
    else if (built_in == B_EXPORT)
        ft_export();
    else if (built_in == B_PWD)
        ft_pwd();
    else if (built_in == B_UNSET)
        ft_unset();
}

char    *ft_make_it_one_string(char **array)
{
    char    str;
    int i;

    i = 1;
    str = ft_strdup(array[i]);
    while (array[++i])
        str = ft_strjoin(str, array[i]);
    return (str);
}

bool    ft_check_for_nflag(char **argv)
{
    int i;

    i = 0;
    while (argv[++i])
        if (ft_strnstr(argv[i], "-n", 2))
            return (true);
    return (false); 
}

//          syntax will be checked earlier (before calling the echo function)
int ft_echo(char **argv, int *fd, t_error *err)
{
    char    *string;

    string = NULL;
    if (!argv || !*argv || !fd)
        return (err->echo = 1); 
    if (!fd[0])
    {
        string = get_next_line(fd[0]);
        while (string)
        {
            ft_putstr_fd(string, fd[1]);
            string = get_next_line(fd[0]);
        }
    }
    else if (ft_check_for_nflag(argv))
        ft_putendl_fd(make_it_one_string(argv), fd[1]);
    else
        ft_putstr_fd(make_it_one_string(argv), fd[1]);
    return (err->echo = 0);
}