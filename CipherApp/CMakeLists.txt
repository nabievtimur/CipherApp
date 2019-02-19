# CMakeList.txt: проект CMake для CMakeCipherApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(HEADER pch.h Cipher.h MathCore.h Utills.h)
set(SOURCE pch.cpp CipherApp.cpp Cipher.cpp CTRCipher.cpp OFBCipher.cpp MathCore.cpp Utills.cpp)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CipherApp "CipherApp.cpp" "pch.h")



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
