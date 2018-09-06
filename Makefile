CC		= g++

RM		= rm -rf

NAME		= bomberman

SRCS		= src/Bomberman.cpp \
		  src/Game.cpp \
		  src/main.cpp \
		  src/Entities/AEntity.cpp \
		  src/Entities/RandomEntity.cpp \
		  src/Entities/BombUp.cpp \
		  src/Entities/PowerUp.cpp \
		  src/Entities/BlocUp.cpp \
		  src/Entities/LifeUp.cpp \
		  src/Map/Cell.cpp \
		  src/Map/Map.cpp \
		  src/Menus/Menu.cpp \
		  src/Menus/MenuSolo.cpp \
		  src/Menus/Pause.cpp \
		  src/Menus/Splash.cpp \
		  src/Players/AI.cpp \
		  src/Players/APlayer.cpp \
		  src/Players/Bomb.cpp \
		  src/Players/Controller.cpp \
		  src/Players/Player.cpp

OBJS		= $(SRCS:.cpp=.o)

CPPFLAGS	= -I include -W -Wall -Werror -Wextra -std=c++11

GRAPHFLAGS	= -L lib/SFML -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

temp=-L lib/SFML/

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS) $(GRAPHFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
