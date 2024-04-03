#[[
  SYCL Academy (c)

  SYCL Academy is licensed under a Creative Commons Attribution-ShareAlike 4.0
  International License.

  You should have received a copy of the license along with this work.  If not,
  see <http://creativecommons.org/licenses/by-sa/4.0/>.
]]

# CMake function to build ab AdaptiveCpp configuration and create executable binaries
# from AdaptiveCpp libraries.
function( add_sycl_executable_adaptivecpp prefix source )
  set(TARGET_NAME "${prefix}_${source}")
  add_executable("${TARGET_NAME}" "${source}.cpp")
  add_sycl_to_target(TARGET ${TARGET_NAME} SOURCES "${source}.cpp")

  target_include_directories("${prefix}_${source}" PRIVATE
    ${PROJECT_SOURCE_DIR}/Utilities/include
    ${PROJECT_SOURCE_DIR}/External/stb)
  target_link_libraries("${prefix}_${source}" PRIVATE Threads::Threads)
  target_link_libraries("${prefix}_${source}" PUBLIC Catch2::Catch2)
  set_target_properties("${prefix}_${source}" PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
endfunction()

# CMake function to build a DPC++ configuration and create executable binaries
# from oneAPI libraries.
function( add_sycl_executable_dpcpp prefix source )
  set(TARGET_NAME "${prefix}_${source}")

  add_executable(${TARGET_NAME} "${source}.cpp")
  # This function is from IntelSYCL cmake module
  add_sycl_to_target(TARGET ${TARGET_NAME} SOURCES "${source}.cpp")
  target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/External/Catch2/single_include")
  target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/External/stb")
  target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities/include")
  target_link_libraries(${TARGET_NAME} PUBLIC Catch2::Catch2)
endfunction()

function( add_sycl_executable prefix source )
  if (SYCL_ACADEMY_USE_DPCPP)
    add_sycl_executable_dpcpp(${prefix} ${source})
  endif()
  if (SYCL_ACADEMY_USE_ADAPTIVECPP)
    add_sycl_executable_adaptivecpp(${prefix} ${source})
  endif()
endfunction()



add_subdirectory(Section_6_What_is_SYCL)
add_subdirectory(Section_8_Enqueueing_a_Kernel)
add_subdirectory(Section_9_Managing_Data)
add_subdirectory(Section_14_Handling_Errors)
add_subdirectory(Section_2_Device_Discovery)
add_subdirectory(Section_26_Data_Parallelism)
add_subdirectory(Section_25_Using_USM)
add_subdirectory(Section_7_Asynchronous_Execution)
add_subdirectory(Section_22_Data_and_Dependencies)
add_subdirectory(Section_23_In_Order_Queue)
add_subdirectory(Section_1_Advanced_Data_Flow)
add_subdirectory(Section_24_Multiple_Devices)
add_subdirectory(Section_3_Image_Convolution)
add_subdirectory(Section_13_Coalesced_Global_Memory)
add_subdirectory(Section_4_Local_Memory_Tiling)
add_subdirectory(Section_18_Work_Group_Sizes)
add_subdirectory(Section_15_Matrix_Transpose)
