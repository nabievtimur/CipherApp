project(CipherApp)
cmake_minimum_required (VERSION 3.8)

set(HEADER pch.h Cipher.h MathCore.h Utills.h)
set(SOURCE pch.cpp CipherApp.cpp Cipher.cpp CTRCipher.cpp OFBCipher.cpp MathCore.cpp Utills.cpp)

file(GLOB CPPS "*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)