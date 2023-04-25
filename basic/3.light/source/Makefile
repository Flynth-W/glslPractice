OBJS = ./main.o ./app/app.o ./scene/one/one.o \
			 ./objets/square/square.o \
			 ./objets/Shader/Shader.o \
			 ./objets/abstract.o \
			 ./objets/cube/cube.o \
			 ./objets/cube1/cube1.o \
			 ./objets/cubeLigth/cubeLigth.o \
			 ./objets/box/box.o \
			 ./objets/boxTwoTexture/boxTwoTexture.o \
			 ./objets/cubeMaterial/cubeMaterial.o \
			 ./utils/camera/camera.o \
			 ./events/events.o 


FILE_BIN = .main.bin
LIBS = -lGL -lglfw -lGLEW
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
%.o:%.cpp
	g++ -c $< -o $@
sh: 
	@ ./mk $(OBJS) $(LIBS) 
clean:
	rm *.o $(FILE_BIN) */*.o */*/*.o
