all:
	g++ GameObject.cpp Camera.o VertexBuffer.o IndexBuffer.o Shader.o main.o glad.o -I.\\include/ -L.\\lib/ -Bstatic -l:libglfw3dll.a -lopengl32 -o out

cc:
	g++ -c GameObject.cpp Camera.cpp VertexBuffer.cpp IndexBuffer.cpp Shader.cpp main.cpp -I.\\include/ -L.\\lib/

main:
	g++ -c main.cpp -I.\\include/ -L.\\lib/

Shader:
	g++ -c Shader.cpp -I.\\include/ -L.\\lib/

VertexBuffer:
	g++ -c VertexBuffer.cpp -I.\\include/ -L.\\lib/

IndexBuffer:
	g++ -c IndexBuffer.cpp -I.\\include/ -L.\\lib/

Camera:
	g++ -c Camera.cpp -I.\\include/ -L.\\lib/

GameObject:
	g++ -c GameObject.cpp -I.\\include/ -L.\\lib/

glad:
	gcc -c glad.c -I.\\include/

clean:
	rm *.o out.exe
