vpath src

main: src/main.c src/block.c src/camera.c /usr/include/glad/glad.c
	gcc src/main.c src/block.c src/camera.c /usr/include/glad/glad.c -o main -lglfw -lm
