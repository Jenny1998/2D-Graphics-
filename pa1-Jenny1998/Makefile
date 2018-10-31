CC = g++ -g

CC_DEBUG = @$(CC) -std=c++11 -Wreturn-type
CC_RELEASE = @$(CC) -std=c++11 -O3 -DNDEBUG

G_SRC = src/*.cpp *.cpp

G_INC = -Iinclude -Iapps -I/Users/reed/brew/Cellar/sdl2/2.0.5/include

G_LINK = -L/Users/reed/brew/Cellar/sdl2/2.0.5/lib

all: image

image : $(G_SRC) apps/image.cpp apps/image_recs.cpp
	$(CC_DEBUG) $(G_INC) $(G_SRC) apps/image.cpp apps/image_recs.cpp -o image

DRAW_SRC = apps/draw.cpp apps/GWindow.cpp apps/GTime.cpp
draw: $(DRAW_SRC) $(G_SRC)
	$(CC_RELEASE) $(G_INC) $(G_SRC) $(G_LINK) $(DRAW_SRC) -lSDL2 -o draw

VIEWER_SRC = apps/viewer.cpp apps/GWindow.cpp apps/GTime.cpp apps/image_recs.cpp
viewer: $(VIEWER_SRC) $(G_SRC)
	$(CC_RELEASE) $(G_INC) $(G_SRC) $(G_LINK) $(VIEWER_SRC) -lSDL2 -o viewer


BOUNCE_SRC = apps/bounce.cpp apps/GWindow.cpp apps/GTime.cpp
bounce: $(BOUNCE_SRC) $(G_SRC)
	$(CC_RELEASE) $(G_INC) $(G_SRC) $(G_LINK) $(BOUNCE_SRC) -lSDL2 -o bounce


clean:
	@rm -rf image draw viewer bounce *.png *.dSYM

