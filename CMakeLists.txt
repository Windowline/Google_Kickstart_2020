cmake_minimum_required(VERSION 3.27)
project(Google_KickStart_2020)

set(CMAKE_CXX_STANDARD 17)


# Round A
add_executable(Round_A_Allocation
        Round_A/Allocation.cpp
)

add_executable(Round_A_Plates
        Round_A/Plates.cpp
)

add_executable(Round_A_Workout_Solve1
        Round_A/Workout_Solve1.cpp
)

add_executable(Round_A_Workout_Solve2
        Round_A/Workout_Solve2.cpp
)

add_executable(Round_A_Bundling
        Round_A/Bundling.cpp
)

add_executable(Round_B_Bike_Tour
        Round_B/Bike_Tour.cpp
)

add_executable(Round_B_Bus_Routes_Solve1
        Round_B/Bus_Routes_Solve1.cpp
)

add_executable(Round_B_Bus_Routes_Solve2
        Round_B/Bus_Routes_Solve2.cpp
)

add_executable(Round_B_Robot_Path_Decoding
        Round_B/Robot_Path_Decoding.cpp
)

