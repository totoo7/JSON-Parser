cmake_minimum_required(VERSION 3.5.0)
set (CMAKE_CXX_STANDARD 11)
project(JSON-Parser VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources 
    main.cpp

    src/view/Interface.cpp
    src/controllers/Validator.cpp
    src/controllers/Controller.cpp
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
    src/services/creators/ArrayCreator.cpp
    src/services/children/JsonString.cpp
    src/services/children/JsonInt.cpp
    src/services/children/JsonBool.cpp
    src/services/children/JsonFloat.cpp
    src/services/children/JsonNull.cpp
    src/services/children/JsonObject.cpp
    src/services/children/JsonArray.cpp
)

add_executable(JSON-Parser ${sources})

list(APPEND includePath 
    "include/controllers" 
    "include/services/creators" 
    "include/services/children" 
    "include/services" 
    "include/view"
)
target_include_directories(${PROJECT_NAME} PUBLIC ${includePath})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
