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
snake-cli: type ui
	@echo building $(MAIN_BIN_DIR)/snake-cli.exe
	@gcc -o $(MAIN_BIN_DIR)/snake-cli.exe $(SRC_DIR)/Main.c $(MAIN_OBJ_DIR)/*.o -Iinclude


# =============================================================================
#                              Test Executables
# =============================================================================
type.StringTest: UnitTest.o String.o StringTest.o
	@echo building $(TEST_BIN_DIR)/type.String.exe
	@gcc -o $(TEST_BIN_DIR)/type.String.exe $(TEST_OBJ_DIR)/StringTest.o\
	    $(MAIN_OBJ_DIR)/UnitTest.o $(MAIN_OBJ_DIR)/String.o


# =============================================================================
#                                Source Files
# =============================================================================
type: String.o
ui: CommandLineInterface.o

UnitTest.o:
	@echo compiling $(SRC_DIR)/test/UnitTest.c
	@gcc -o $(MAIN_OBJ_DIR)/UnitTest.o -c $(SRC_DIR)/test/UnitTest.c -Iinclude

String.o:
	@echo compiling $(SRC_DIR)/type/String.c
	@gcc -o $(MAIN_OBJ_DIR)/String.o -c $(SRC_DIR)/type/String.c -Iinclude

CommandLineInterface.o:
	@echo compiling $(SRC_DIR)/ui/CommandLineInterface.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandLineInterface.o\
	     -c $(SRC_DIR)/ui/CommandLineInterface.c -Iinclude

# =============================================================================
#                                 Test Files
# =============================================================================
# type
StringTest.o:
	@echo compiling $(TEST_DIR)/type/StringTest.c
	@gcc -o $(TEST_OBJ_DIR)/StringTest.o\
	     -c $(TEST_DIR)/type/StringTest.c -Iinclude


# =============================================================================
#                              Build Directories
# =============================================================================
build-dir:
	@echo creating build directories
	@pwsh $(SCRIPTS_DIR)/CreateBuildDirectory.ps1


# =============================================================================
#                                 Unit Tests
# =============================================================================
check: clean-test build-dir type.StringTest
	@echo running unit tests
	@pwsh $(SCRIPTS_DIR)/RunTests.ps1


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
