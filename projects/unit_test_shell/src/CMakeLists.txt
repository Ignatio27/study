target_sources(Shell_test_lib
	PRIVATE
		shel_sort.cpp
	PUBLIC
		shel_sort.hpp
)

target_include_directories(Shell_test_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
