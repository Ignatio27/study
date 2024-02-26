set(SOURCES 
	test_shell.cpp
)

add_executable(test_shell ${SOURCES})
target_link_libraries(test_shell 
	gtest_main 
	gmock_main 
	Shell_test_lib
)

add_test(test_shell test_shell)
