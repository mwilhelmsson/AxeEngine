##
# AxeEngine
#
# @file
# @version 0.1

all:
	g++ axeengine.cpp game.cpp TextureManager.cpp Map.cpp Vector2D.cpp Collision.cpp -lSDL2 -lSDL2_image -o build/axeengine

# end
