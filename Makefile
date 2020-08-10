# =============================================================================
# Makefile to build snake-cli project.
# 
# Platform: Windows 10
# Author: Renan Kummer
# =============================================================================

# =============================================================================
#                                  Build All
# =============================================================================
all: build
build: build-dir snake-cli

# =============================================================================
#                                  Constants
# =============================================================================
SRC_DIR  = src
TEST_DIR = test

BUILD_DIR = build
MAIN_OBJ_DIR = ${BUILD_DIR}/main/obj
MAIN_BIN_DIR = $(BUILD_DIR)/main/bin
TEST_OBJ_DIR = $(BUILD_DIR)/test/obj
TEST_BIN_DIR = $(BUILD_DIR)/test/bin

RESOURCES_DIR = resources
SCRIPTS_DIR   = $(RESOURCES_DIR)/scripts

# =============================================================================
#                              Main Executables
# =============================================================================
snake-cli: type ui util
	@echo building $(MAIN_BIN_DIR)/snake-cli.exe
	@gcc -o $(MAIN_BIN_DIR)/snake-cli.exe $(SRC_DIR)/Main.c\
	    $(MAIN_OBJ_DIR)/*.o -Iinclude


# =============================================================================
#                              Test Executables
# =============================================================================
test-manual: manual.CommandLineInterfaceTest
test-type: type.WindowCoordinateTest
test-util: util.StringUtilsTest

manual.CommandLineInterfaceTest: CommandLineInterface.o\
                                 CommandLineInterfaceTest.o\
                                 StringUtils.o WindowCoordinate.o
	@echo building $(TEST_BIN_DIR)/manual.CommandLineInterfaceTest.exe
	@gcc -o $(TEST_BIN_DIR)/manual.CommandLineInterfaceTest.exe\
	    $(TEST_OBJ_DIR)/CommandLineInterfaceTest.o\
	    $(MAIN_OBJ_DIR)/CommandLineInterface.o $(MAIN_OBJ_DIR)/StringUtils.o\
	    $(MAIN_OBJ_DIR)/WindowCoordinate.o

type.WindowCoordinateTest: UnitTest.o WindowCoordinate.o WindowCoordinateTest.o
	@echo building $(TEST_BIN_DIR)/type.WindowCoordinateTest.exe
	@gcc -o $(TEST_BIN_DIR)/type.WindowCoordinateTest.exe\
	    $(TEST_OBJ_DIR)/WindowCoordinateTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
	    $(MAIN_OBJ_DIR)/WindowCoordinate.o

util.StringUtilsTest: UnitTest.o StringUtils.o StringUtilsTest.o
	@echo building $(TEST_BIN_DIR)/type.StringUtilsTest.exe
	@gcc -o $(TEST_BIN_DIR)/type.StringUtilsTest.exe\
	    $(TEST_OBJ_DIR)/StringUtilsTest.o\
	    $(MAIN_OBJ_DIR)/UnitTest.o $(MAIN_OBJ_DIR)/StringUtils.o


# =============================================================================
#                                Source Files
# =============================================================================
type: WindowCoordinate.o
ui: CommandLineInterface.o
util: StringUtils.o

# ui
WindowCoordinate.o:
	@echo compiling $(SRC_DIR)/type/WindowCoordinate.c
	@gcc -o $(MAIN_OBJ_DIR)/WindowCoordinate.o\
	     -c $(SRC_DIR)/type/WindowCoordinate.c -Iinclude

# type
CommandLineInterface.o:
	@echo compiling $(SRC_DIR)/ui/CommandLineInterface.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandLineInterface.o\
	     -c $(SRC_DIR)/ui/CommandLineInterface.c -Iinclude

# util
StringUtils.o:
	@echo compiling $(SRC_DIR)/util/StringUtils.c
	@gcc -o $(MAIN_OBJ_DIR)/StringUtils.o\
	    -c $(SRC_DIR)/util/StringUtils.c -Iinclude

UnitTest.o:
	@echo compiling $(SRC_DIR)/util/UnitTest.c
	@gcc -o $(MAIN_OBJ_DIR)/UnitTest.o -c $(SRC_DIR)/util/UnitTest.c -Iinclude


# =============================================================================
#                                 Test Files
# =============================================================================
# type
WindowCoordinateTest.o:
	@echo compiling $(TEST_DIR)/type/WindowCoordinateTest.c
	@gcc -o $(TEST_OBJ_DIR)/WindowCoordinateTest.o\
	     -c $(TEST_DIR)/type/WindowCoordinateTest.c -Iinclude

# ui
CommandLineInterfaceTest.o:
	@echo compiling $(TEST_DIR)/ui/CommandLineInterfaceTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandLineInterfaceTest.o\
	     -c $(TEST_DIR)/ui/CommandLineInterfaceTest.c -Iinclude

# util
StringUtilsTest.o:
	@echo compiling $(TEST_DIR)/util/StringUtilsTest.c
	@gcc -o $(TEST_OBJ_DIR)/StringUtilsTest.o\
	     -c $(TEST_DIR)/util/StringUtilsTest.c -Iinclude


# =============================================================================
#                              Build Directories
# =============================================================================
build-dir:
	@echo creating build directories
	@pwsh $(SCRIPTS_DIR)/CreateBuildDirectory.ps1


# =============================================================================
#                                 Unit Tests
# =============================================================================
check: clean-test build-dir test-type test-util
	@echo running unit tests
	@pwsh $(SCRIPTS_DIR)/RunTests.ps1

check-manual: clean-test build-dir test-manual

# =============================================================================
#                                   Cleanup
# =============================================================================
clean:
	@echo clearing build directories
	@pwsh $(SCRIPTS_DIR)/DeleteBuildDirectory.ps1

clean-test:
	@echo clearing test build directories
	@pwsh $(SCRIPTS_DIR)/DeleteTestBuildDirectories.ps1
	@pwsh $(SCRIPTS_DIR)/CreateBuildDirectory.ps1
