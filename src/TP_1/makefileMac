OPENCV_LIBS = -L../../lib/ -lIlmImf -llibtiff -lopencv_imgcodecs -lippicv -llibwebp -lopencv_imgproc -llibjasper -lopencv_core -lzlib -llibjpeg -lopencv_hal -llibpng -lopencv_highgui
OSX_LIBS = -framework OpenCL -framework Cocoa
INC = -I../../include/

all : display_image

tp1: tp1.cpp
	$(CXX) -c tp1.cpp $(INC)

display_image : tp1
	$(CXX) -o display_image tp1.o $(OSX_LIBS) $(OPENCV_LIBS)

clean :
	rm *.o display_image