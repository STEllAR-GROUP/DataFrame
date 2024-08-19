set(dependencies DataFrame)
if(HMDF_HPX)
  set(dependencies ${dependencies} HPX::wrap_main)
endif()

add_executable(hello_world hello_world.cc)
target_link_libraries(hello_world PRIVATE ${dependencies})
