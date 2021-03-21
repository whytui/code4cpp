project(ch17)

message(STATUS "Generating ch17..")

# for循环加入源文件
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(file ${files})
    get_filename_component(name `${file} NAME)
    add_executable(${name} ${file})
    if(UNIX OR Linux)
        target_link_libraries(${name} pthread)
    endif()
endforeach()