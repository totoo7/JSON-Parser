cmake_minimum_required(VERSION 3.5.0)
project(JSON-Parser VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources 
    main.cpp

    src/controllers/validator.cpp
    src/controllers/controller.cpp
    src/services/Json.cpp
    src/services/JsonPair.cpp
    src/services/JsonFactory.cpp
    src/services/creators/JsonCreator.cpp
    src/services/creators/ObjectCreator.cpp
    src/services/creators/StringCreator.cpp
    src/services/creators/BoolCreator.cpp
    src/services/creators/FloatCreator.cpp
    src/services/creators/IntCreator.cpp
    src/services/creators/NullCreator.cpp
    src/services/children/JsonString.cpp
    src/services/children/JsonInt.cpp
    src/services/children/JsonBool.cpp
    src/services/children/JsonFloat.cpp
    src/services/children/JsonNull.cpp
)

add_executable(JSON-Parser ${sources})
list(APPEND includePath "include/controllers" "include/services/creators" "include/services/children" "include/services" "include/view")
target_include_directories(${PROJECT_NAME} PUBLIC ${includePath}>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
