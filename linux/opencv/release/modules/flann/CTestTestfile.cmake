# CMake generated Testfile for 
# Source directory: /home/bravej/Documents/AnalyseImage/linux/opencv/modules/flann
# Build directory: /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/flann
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_flann "/home/bravej/Documents/AnalyseImage/linux/opencv/release/bin/opencv_test_flann" "--gtest_output=xml:opencv_test_flann.xml")
set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "/home/bravej/Documents/AnalyseImage/linux/opencv/release/test-reports/accuracy")
