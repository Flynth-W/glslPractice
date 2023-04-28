OBJS = ./main.o ./app/app.o ./scene/one/one.o \
			 ./objets/square/square.o \
			 ./objets/Shader/ShaderObj.o \
			 ./objets/cube/cube.o \
			 ./objets/abstract.o \
			 ./objets/cubeLigth/cubeLigth.o \
			 ./model/guitar/guitar.o \
			 ./model/model.o \
			 ./utils/camera/camera.o \
			 ./events/events.o 


FILE_BIN = .main.bin
LIBS = -lGL -lglfw -lGLEW -lassimp
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
%.o:%.cpp
	g++ -c $< -o $@
sh: 
	@ ./mk $(OBJS) $(LIBS) 
clean:
	rm *.o $(FILE_BIN) */*.o */*/*.o
