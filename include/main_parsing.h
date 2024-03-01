#ifndef MAINPARSING_H
#define MAINPARSING_H

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024
# define ERROR "Error\n"
# define OPEN_FD_ERROR "Error : could not open file\n"
# define CLOSE_FD_ERROR "Error : could not close file\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>



/*****************************************/
/*           GENERAL STRUCTURES          */
/*****************************************/

typedef struct s_texture
{
    int no_fd;
    int so_fd;
    int we_fd;
    int ea_fd;

} t_texture;

typedef struct s_mapinfo
{
    int width;
    
} t_mapinfo;

typedef struct s_img{
	void	*mlx;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	// t_img		img;
	int			width;
	int			height;
} t_window;

typedef struct s_data
{
    char *file;
    size_t file_size;

    t_img       img;
	void		*mlx;
	void		*win;
	int			width;
	int			height;

    int *floor_col[3]; //           floor's color in RGB
    int *ceiling_col[3]; //         ceiling's color in RGB
    t_texture *texture; //          contains the 4 cardinal points' fds

} t_data;

/*****************************************/
/*           PARSING STRUCTURE           */
/*****************************************/

typedef struct s_checklist
{
    int no_done;
    int so_done;
    int we_done;
    int ea_done;
    int f_done;
    int c_done; //                  a struct to check if there are duplicates in the cub file

} t_checklist;


int safe_open(char *file_name);
void safe_close(int fd);


#endif