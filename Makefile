vpath src

main: src/main.c src/block.c src/camera.c /usr/include/glad/glad.c /usr/include/stb/stb.c
	gcc src/main.c src/block.c src/camera.c /usr/include/glad/glad.c /usr/include/stb/stb.c -o main -lglfw -lm
