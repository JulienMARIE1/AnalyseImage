OPENCV_LIBS = -L../../lib/ -lIlmImf -llibtiff -lopencv_imgcodecs -lippicv -llibwebp -lopencv_imgproc -llibjasper -lopencv_core -lzlib -llibjpeg -lopencv_hal -llibpng -lopencv_highgui
OSX_LIBS = -framework OpenCL -framework Cocoa
INC = -I../../include/

all : image_expansion  

compute_histogramTmp: image_expansion.cpp compute_histogram.cpp 
	$(CXX) -c image_expansion.cpp compute_histogram.cpp $(INC)

image_expansion : compute_histogramTmp
	$(CXX) -o image_expansion image_expansion.o compute_histogram.o $(OSX_LIBS) $(OPENCV_LIBS)

clean :
	rm *.o image_expansion