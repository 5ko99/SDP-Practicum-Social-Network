cmake_minimum_required(VERSION 3.15)
project(SDP_Practicum_Social_Network)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDP_Practicum_Social_Network main.cpp User.h Commands/Command.h Commands/AddUserCommand.h Commands/ExitCommand.h Functionality/Invoker.h Commands/DeleteCommand.h Commands/LinkCommand.h Commands/FindCommand.h Commands/BanCommand.h Commands/DelinkCommand.h Commands/RecommendCommand.h Functionality/AddUser.h Global.h Functionality/FindUser.h Functionality/DeleteUser.h Utils/DynamicArray.h Utils/DynamicGraph.h Functionality/LinkUsers.h Commands/UnbanCommand.h Functionality/Recommend.h Functionality/Exit.h)