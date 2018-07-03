find_package(Snapd REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)

add_executable(snaptest main.cpp)
target_link_libraries(snaptest Snapd::Core Qt5::Core Qt5::Network)
