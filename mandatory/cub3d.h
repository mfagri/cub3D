/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:42:02 by mmardi            #+#    #+#             */
/*   Updated: 2022/07/31 17:18:29 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <string.h>

# define PI 3.14159265359
# define FOV_ANGLE 1.0471975512  //60 * (PI/180)
# define WALL_SPRIT 1
# define NUM_RAYS 320
# define FALSE 0
# define TRUE 1
# define WALL_SIZE 64
# define MINIMAP_SIZE 2
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define ARW_LEFT 124
# define ARW_RIGHT 123

typedef struct textter {
	char	*so;
	char	*we;
	char	*ea;
	char	*no;
	int		bits;
	int		line;
	int		endian;
	char	**str;
	char	*addr;
	char	*dst;
}	t_textter;

typedef struct caster
{
	int		wallhitx;
	int		wallhity;
	int		rayisup;
	int		rayisdown;
	int		rayisleft;
	int		rayisright;
	float	distance;
	float	ystep;
	float	xstep;
	float	yintercept;
	float	xintercept;
	float	hhitx;
	float	hhity;
	float	x_chk;
	float	y_chk;
	int		findhorzwall_hit;
	int		findvir_wall;
	float	vhitx;
	float	vhity;
	double	horz_dist;
	double	vert_dist;
	float	vx_chk;
	float	vy_chk;
}	t_caster;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*dst;
	int		newx;
	int		newy;
}	t_img;

typedef struct s_ray
{
	float	ray_angle;
	float	wallhitx;
	float	wallhity;
	float	distane;
	int		washitvertical;
	int		is_faceingup;
	int		is_facingdown;
	int		is_facingleft;
	int		is_facingright;
	int		wallhitcomtent;
}	t_ray;

typedef struct s_colors
{
	int	f[3];
	int	c[3];
}	t_colors;

typedef struct p_player
{
	int		x;
	int		y;
	int		turn_d;
	int		wlk_d;
	double	rotatangle;
	float	move_speed;
	float	rotation_speed;
}	t_player;

typedef struct s_rend {
	char			**map;
	void			*mlx;
	void			*mlx_win;
	char			player;
	unsigned int	buffer[4][64 * 64];
	float			angel;
	void			*wall;
	void			*empty;
	void			*spaces;
	void			*p;
	int				roa;
	int				mapx;
	int				mapy;
	void			*black;
	void			*floor;
	t_colors		*colors;
	t_textter		*textter;
	t_player		*pplayer;
	t_ray			*rays;
	t_caster		*caster;
	int				width;
	int				height;
	int				i;
	int				d;
	int				n;
	int				j;
	char			direction;
	int				key_d;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_left;
	int				key_right;
	float			raydist;
}	t_rend;

//////PARSING FOLDER
// check_extension.c
void			check_extension(char *av);

// map_filling.c
char			**ft_free(char *s, char **map);
char			**map_filling(int fd);

// utils.c
size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_strchr(char *s, int c);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strlen(const	char *s);
char			*ft_strjoin(char *s1, char *s2);

// utils2.c
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *s);

// colors_and_new_line.c
int				ft_check_new_line(char **map, char *s);
int				ft_check_new_line_1(char *map, char *s);
int				check_space_colors(char *s, int *k);
int				check_linebyline(char *s, int i, char *map);
int				check_colors(char **six_lines, int i, int k, int j);

// map_checking.c
int				check_first_sixlines(char *s);
int				check_textures(char **six_lines);
int				check_duplicate_elements(char **six_lines);
int				ft_check_new_line(char **map, char *s);
int				map_final_check(char **map, t_rend *game);

// map_parsing.c
void			init_structers(char **element, char player, t_rend *game);
void			init_textters(char *s, char **element, int i, t_rend *game);
void			init_colors(char *s, char **element, int i, t_rend *game);
int				check_player(char **map, int i, int *k, char *p);
int				check_map_is_close(char **map, int i, char c, char p);
int				check_map_is_close_norm(char **map, int i, int j, char p);
int				map_parsing(char **six_lines, char **map, t_rend *game);
///////////////////////////

////// GAMEPLAY ////////
// player_moves.c
void			move_up(t_rend *m, int x, int y);
void			move_down(t_rend *m, int x, int y);
void			move_left(t_rend *m, int x, int y);
void			move_right(t_rend *m, int x, int y);
void			player_next_position(t_rend *m, int i);

// take_keys.c
void			get_index(t_rend *m, int *x, int *y);
void			player_rendering(t_rend *m);
int				key_press(int key, t_rend *m);
int				key_release(int key, t_rend *m);

// ray_position.c
void			horizontal_wall_hit(t_rend *m);
void			vertical_wall_hit(t_rend *m);
void			horizontal_ray(t_rend *m, float rayangel);
void			vertical_ray(t_rend *m, float rayangel);

// raycasting_utils.c
int				is_end_window(t_rend *m, double x, double y);
int				is_wall(t_rend *m, int x, int y, char identf);
float			normaliseangle(float angle);
float			distancebetwenpoint(float x1, float y1, float x2, float y2);
void			ft_init_caster(t_rend *m);

// raycasting.c
void			ft_ray_distance(t_rend *m, int i);
void			cast_singleray(float rayangel, int i, t_rend *m);
void			rays(t_rend *m);
unsigned long	create_rgb(int r, int g, int b);
void			new_x_y(t_img *img, t_rend *m, int i);

// new_map.c
int				lines(char **map);
int				longest_line_in_map(char **map);
void			fill_eol_with_one(t_rend *game, char **map);

// window_creation.c
void			fill_buffer(t_rend *m);
void			set_screen_pixel(t_img *screen, int i, int j, int color);
void			put_wall(t_rend *m, int wall_h, int i, int c);
void			projectewall3d(t_rend *m);
unsigned long	createRGB(int r, int g, int b);
int				image_rendering(t_rend *game);
void			player_init(t_rend *m);
void			mlx_start(char **map, t_rend *game);
char			**final_map(t_rend *game, char **map);

// wall_textures.c
void			projectewall3d(t_rend *m);
void			put_wall(t_rend *m, int wall_h, int i, int c);
void			fill_buffer(t_rend *m);

// draw_background.c
void			set_screen_pixel(t_img *screen, int i, int j, int color);

void			floor_and_ceilling(t_rend *m, int i, int c);
////////////////////////
void			ft_allocation_err(void);
int				ft_exit(t_rend *m);
//ddaray
void			ddaray(int i, t_img *img, t_rend *m);
void			ray_mini(t_img *img, t_rend *m);
#endif
