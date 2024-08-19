
set(dependencies DataFrame)
if(HMDF_HPX)
  set(dependencies ${dependencies} HPX::wrap_main)
endif()

add_executable(dataframe_performance dataframe_performance.cc)
target_link_libraries(dataframe_performance PRIVATE ${dependencies})

add_executable(dataframe_performance_2 dataframe_performance_2.cc)
target_link_libraries(dataframe_performance_2 PRIVATE ${dependencies})

add_executable(linkedin_benchmark linkedin_benchmark.cc)
target_link_libraries(linkedin_benchmark PRIVATE ${dependencies})
