##
# AxeEngine
#
# @file
# @version 0.1

all:
	g++ axeengine.cpp game.cpp TextureManager.cpp GameObject.cpp Map.cpp -lSDL2 -lSDL2_image -o build/axeengine

# end
