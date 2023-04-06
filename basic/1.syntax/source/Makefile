OBJS = ./main.o ./app/app.o ./scene/one/one.o \
			 ./objets/square/square.o \
			 ./objets/Shader/Shader.o


FILE_BIN = .main.bin
LIBS = -lGL -lglfw -lGLEW
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
%.o:%.cpp
	g++ -c $< -o $@
clean:
	rm *.o $(FILE_BIN) */*.o */*/*.o
