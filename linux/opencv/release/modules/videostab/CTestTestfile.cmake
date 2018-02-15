# CMake generated Testfile for 
# Source directory: /home/bravej/Documents/AnalyseImage/linux/opencv/modules/videostab
# Build directory: /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/videostab
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_videostab "/home/bravej/Documents/AnalyseImage/linux/opencv/release/bin/opencv_test_videostab" "--gtest_output=xml:opencv_test_videostab.xml")
set_tests_properties(opencv_test_videostab PROPERTIES  LABELS "Main;opencv_videostab;Accuracy" WORKING_DIRECTORY "/home/bravej/Documents/AnalyseImage/linux/opencv/release/test-reports/accuracy")
