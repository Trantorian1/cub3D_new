/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:05 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/01 17:48:38 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "main_parsing.h"


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>

int get_map_nb_lines(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int check_map_first_line(char **map)
{
	int i;
	int j;

	j = 0;
	int len = get_map_nb_lines(map);
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (-1);

		i = 0;
		while (i < len && map[i][j] && map[i][j] == ' ')
		{				
			++i;
			if (i < len)
			{
				if (map[i][j] 
					&& (map[i][j] != ' ' && map[i][j] != '1')
					|| ((map[i][j] && map[i][j] != '1' && map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
					|| (map[i][j] && map[i][j] != '1' && map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' ')))
						return (-1);
			}

		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int check_map_last_line(char **map)
{
	int i;
	int j;
	int end;

	end = get_map_nb_lines(map) - 1;
	j = 0;
	while (map[end][j])
	{
		if (map[end][j] != '1' && map[end][j] != ' ')
			return (-1);

		i = end;
		while (i >= 0 && map[i][j] && map[i][j] == ' ')
		{				
			--i;
			if (i >= 0)
			{
				if (map[i][j] 
					&& (map[i][j] != ' ' && map[i][j] != '1')
					|| ((map[i][j] && map[i][j] != '1' && map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
					|| (map[i][j] && map[i][j] != '1' && map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' ')))
						return (-1);
			}

		}
		j++;
	}
	return (EXIT_SUCCESS);
}


//check les murs exterieurs gauche et droite :
// faire while(espace) pour passer les espaces, puis verifier que c'est un 1 ou que 
// toute la ligne est vide

int main()
{
	char **map;

	map = (char**)malloc(4 * sizeof(char*));

    // Assigning values to each element in the array
    map[0] = " 111110111";
    map[1] = " 101  1001";
    map[2] = " 111  1111";

	printf("%d\n", check_map_last_line(map));

	return (0);
}

// int check_valid_map(char **map)
// {
// 	int i;
// 	int i_tmp;
// 	int j;

// 	j = 0;

// 	//ON PARSE LA PREMIERE LIGNE DE LA MAP



// }

//ft_map
// {
	//POUR CHAQUE LIGNE
	//check que 1ere et derniere ligne ne sont que des 1

	
// }

int parse_file(int fd)
{
	//POUR CHAQUE LIGNE
	//if les 2 premiers caracteres sont NO ou SO ou WE ou EA et le 3e est ' '
		//avancer jusqu'a ce qu'il n'y ait plus d'espaces
		//if le reste de la ligne (jusqu'au 1er \n) est un path valide
			//enregistrer le path dans le pt cardinal correspondant
	
	//else if le 1er est F ou C et le 3e un ' '
		//avancer jusqu'a ce qu'il n'y ait plus d'espaces
		//if le reste de la ligne jusqu'a la prochaine virgule est 
		//un ft_atoi valide, qu'il y a une virgule, et ainsi de suite jusqu'a \n
		//enregistrer le RGB dans le F ou C correspondant
	
	//else if ligne vide : passer au prochain \n 

	//else :
		//if ft_map pas valide : return error
	
	return (EXIT_SUCCESS);
}

/*

1. 1er ligne : regarder s'il y a un espace, 
descendre jusqu'a ce qu'on trouve un 1

derniere ligne : pareil, vers le haut


2. trouver le width le plus grand et le height le plus grand
faire un char ** de cette taille-la

3. verifier les doublons pour NO SO etc


*/