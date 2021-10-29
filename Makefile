CXX=g++
CXXFLAGS= -std=c++11 -g -fprofile-arcs -ftest-coverage

SRC_DIR = src
PROJECT_SRC_DIR = src/project
SRCS = $(SRC_DIR)/*.cpp

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

MEMCHECK_RESULTS = ValgrindOut.xml

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

DOXY_DIR = docs/code

STATIC_RESULTS = CppCheckResults.xml

BROWSER = firefox

PROGRAM = cardGame
PROGRAM_TEST = testGame

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := $(PROGRAM)

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o	*.gcov *.gcda *.gcno $(PROGRAM) $(PROGRAM).exe

$(PROGRAM): $(SRC_DIR) $(PROJECT_SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(INCLUDE) \
	$(SRC_DIR)/*.cpp $(PROJECT_SRC_DIR)/*.cpp

memcheck: $(PROGRAM)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM)

static: ${SRC_DIR}
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${INCLUDE} --suppress=missingInclude

style: ${SRC_INCLUDE} ${SRC_DIR}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${SRC_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen $(DOXY_DIR)/doxyfile
