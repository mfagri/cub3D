NAME = cub3D

NAME2 = cub3D_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx

SRC = mandatory/parsing/utils.c \
	mandatory/parsing/utils2.c \
	mandatory/parsing/ft_split.c \
	mandatory/parsing/check_extension.c \
	mandatory/parsing/map_filling.c \
	mandatory/parsing/map_parsing.c \
	mandatory/parsing/map_checking.c \
	mandatory/parsing/colors_and_new_line.c \
	mandatory/parsing/map_parsing2.c \
	mandatory/gameplay/window_creation.c \
	mandatory/gameplay/take_keys.c\
	mandatory/gameplay/raycasting.c\
	mandatory/gameplay/raycasting_utils.c\
	mandatory/gameplay/ray_position.c\
	mandatory/gameplay/player_moves.c \
	mandatory/gameplay/wall_textures.c \
	mandatory/gameplay/new_map.c\
	mandatory/gameplay/draw_background.c\
	mandatory/main.c

SRC2 = bonus/parsing/utils.c \
	bonus/parsing/utils2.c \
	bonus/parsing/ft_split.c \
	bonus/parsing/check_extension.c \
	bonus/parsing/map_filling.c \
	bonus/parsing/map_parsing.c \
	bonus/parsing/map_checking.c \
	bonus/parsing/colors_and_new_line.c \
	bonus/parsing/map_parsing2.c \
	bonus/gameplay/window_creation.c \
	bonus/gameplay/take_keys.c\
	bonus/gameplay/raycasting.c\
	bonus/gameplay/raycasting_utils.c\
	bonus/gameplay/ray_position.c\
	bonus/gameplay/player_moves.c \
	bonus/gameplay/wall_textures.c \
	bonus/gameplay/new_map.c\
	bonus/gameplay/draw_background.c\
	bonus/main.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) mandatory/cub3d.h
	$(CC) $(CFLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

bonus : $(NAME2)
$(NAME2) : $(OBJ2) bonus/cub3d.h
	$(CC) $(CFLAGS) $(SRC2) -lmlx -framework OpenGL -framework AppKit  -o $(NAME2)

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ2)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME2)

re : fclean all

reb : fclean bonus