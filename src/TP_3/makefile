OPENCV_LIBS = -L../../lib/ -lIlmImf -llibtiff -lopencv_imgcodecs -lippicv -llibwebp -lopencv_imgproc -llibjasper -lopencv_core -lzlib -llibjpeg -lopencv_hal -llibpng -lopencv_highgui
OSX_LIBS = -framework OpenCL -framework Cocoa
INC = -I../../include/

all : Sobel

sobelTmp: Sobel.cpp 
	$(CXX) -c Sobel.cpp $(INC)

Sobel : sobelTmp
	$(CXX) -o Sobel Sobel.o $(OSX_LIBS) $(OPENCV_LIBS)

clean :
	rm *.o Sobel