cmake_minimum_required(VERSION 3.0.0)
project(JSON-Parser VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources 
    main.cpp

    src/controllers/validator.cpp
    src/controllers/controller.cpp
    src/services/Json.cpp
    src/services/JsonFactory.cpp
    src/services/creators/JsonCreator.cpp
    src/services/creators/ObjectCreator.cpp
)

add_executable(JSON-Parser ${sources})
list(APPEND includePath "include/controllers" "include/services/creators" "include/services" "include/view")
target_include_directories(${PROJECT_NAME} PUBLIC ${includePath}>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
