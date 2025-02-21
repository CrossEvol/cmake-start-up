# Print all environment variables available to CMake
message(STATUS "Listing all environment variables:")
message(STATUS "=====================================")

# Get all environment variables
execute_process(
    COMMAND "${CMAKE_COMMAND}" -E environment
    OUTPUT_VARIABLE env_vars
)

# Convert the output to a list and sort it
string(REPLACE "\n" ";" env_list "${env_vars}")
list(SORT env_list)

# Print each variable
foreach(var ${env_list})
    message(STATUS "${var}")
endforeach()

