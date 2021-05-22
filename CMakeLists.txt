cmake_minimum_required(VERSION 3.19)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList Program/main.cpp Program/Structure/LinkedList.h Program/Structure/node.h Program/Structure/Iterator.h Program/Structure/JsonBuilder.h dist/json/json.h dist/jsoncpp.cpp Program/Class/Paciente.cpp Program/Class/Paciente.h Program/Class/Enfermedad.cpp Program/Class/Enfermedad.h Program/Proxy.cpp Program/Proxy.h Program/Analisis.cpp Program/Analisis.h Program/Menu/Menu.cpp Program/Menu/Menu.h)