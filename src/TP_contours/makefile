OPENCV_LIBS = -L../../lib/ -lIlmImf -llibtiff -lopencv_imgcodecs -lippicv -llibwebp -lopencv_imgproc -llibjasper -lopencv_core -lzlib -llibjpeg -lopencv_hal -llibpng -lopencv_highgui
OSX_LIBS = -framework OpenCL -framework Cocoa
INC = -I../../include/

all : Contours

sobelTmp: contours.cpp 
	$(CXX) -c contours.cpp $(INC)

Contours : sobelTmp
	$(CXX) -o Contours contours.o $(OSX_LIBS) $(OPENCV_LIBS)

clean :
	rm *.o Sobel