vpath src

main: src/main.c src/world.c src/block.c src/camera.c /usr/include/glad/glad.c /usr/include/stb/stb.c src/chunk.c src/perlin.c 
	gcc src/main.c src/world.c src/block.c src/camera.c /usr/include/glad/glad.c /usr/include/stb/stb.c src/chunk.c src/perlin.c -o main -lglfw -lm
	./main