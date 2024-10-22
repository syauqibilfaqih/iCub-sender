# set up our program
add_executable(icub-sender)

# declare our source files
target_sources(icub-sender PRIVATE main.cpp)

# link with YARP libraries
target_link_libraries(icub-sender PRIVATE YARP::YARP_os
                                          YARP::YARP_init
                                          YARP::YARP_sig)
