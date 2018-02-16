OPENCV_LIBS = -L../../lib/ -lIlmImf -llibtiff -lopencv_imgcodecs -lippicv -llibwebp -lopencv_imgproc -llibjasper -lopencv_core -lzlib -llibjpeg -lopencv_hal -llibpng -lopencv_highgui
OSX_LIBS = -framework OpenCL -framework Cocoa
INC = -I../../include/

all : image_profile_gray image_profile_color 

image_profile_grayTmp: image_profile_gray.cpp
	$(CXX) -c image_profile_gray.cpp $(INC)

image_profile_gray : image_profile_grayTmp
	$(CXX) -o image_profile_gray image_profile_gray.o $(OSX_LIBS) $(OPENCV_LIBS)

image_profile_colorTmp: image_profile_color.cpp
	$(CXX) -c image_profile_color.cpp $(INC)

image_profile_color : image_profile_colorTmp
	$(CXX) -o image_profile_color image_profile_color.o $(OSX_LIBS) $(OPENCV_LIBS)


clean :
	rm *.o image_profile_gray; rm image_profile_color 