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
snake-cli: config converter engine gameplay util
	@echo building $(MAIN_BIN_DIR)/snake-cli.exe
	@gcc -o $(MAIN_BIN_DIR)/snake-cli.exe $(SRC_DIR)/Main.c\
	    $(MAIN_OBJ_DIR)/*.o -Iinclude


# =============================================================================
#                              Test Executables
# =============================================================================
test-manual: engine.CommandLineInterfaceManualTest
test-auto: converter.StringConverterTest\
		   engine.WindowCoordinateTest engine.WindowSizeTest\
		   gameplay.CommandReaderTest gameplay.CommandRunnerTest\
		   gameplay.LevelMapTest\
		   util.StringUtilsTest

# converter
converter.StringConverterTest: UnitTest.o StringConverterTest.o\
                               StringConverter.o StringUtils.o
	@echo building $(TEST_BIN_DIR)/converter.StringConverterTest.exe
	@gcc -o $(TEST_BIN_DIR)/converter.StringConverterTest.exe\
	    $(TEST_OBJ_DIR)/StringConverterTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
		$(MAIN_OBJ_DIR)/StringConverter.o $(MAIN_OBJ_DIR)/StringUtils.o

# engine
engine.CommandLineInterfaceManualTest: CommandLineInterface.o\
                                       CommandLineInterfaceManualTest.o\
                                       StringUtils.o StringConverter.o\
								       WindowCoordinate.o WindowSize.o
	@echo building $(TEST_BIN_DIR)/engine.CommandLineInterfaceManualTest.exe
	@gcc -o $(TEST_BIN_DIR)/engine.CommandLineInterfaceManualTest.exe\
	    $(TEST_OBJ_DIR)/CommandLineInterfaceManualTest.o\
	    $(MAIN_OBJ_DIR)/CommandLineInterface.o $(MAIN_OBJ_DIR)/StringUtils.o\
	    $(MAIN_OBJ_DIR)/WindowCoordinate.o $(MAIN_OBJ_DIR)/WindowSize.o\
		$(MAIN_OBJ_DIR)/StringConverter.o

engine.WindowCoordinateTest: UnitTest.o WindowCoordinateTest.o\
                             WindowCoordinate.o WindowSize.o
	@echo building $(TEST_BIN_DIR)/engine.WindowCoordinateTest.exe
	@gcc -o $(TEST_BIN_DIR)/engine.WindowCoordinateTest.exe\
	    $(TEST_OBJ_DIR)/WindowCoordinateTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
	    $(MAIN_OBJ_DIR)/WindowCoordinate.o $(MAIN_OBJ_DIR)/WindowSize.o

engine.WindowSizeTest: UnitTest.o WindowSizeTest.o WindowSizeTest.o
	@echo building $(TEST_BIN_DIR)/engine.WindowSizeTest.exe
	@gcc -o $(TEST_BIN_DIR)/engine.WindowSizeTest.exe\
	    $(TEST_OBJ_DIR)/WindowSizeTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
	    $(MAIN_OBJ_DIR)/WindowSize.o

# gameplay
gameplay.CommandReaderTest: UnitTest.o CommandReaderTest.o CommandReader.o\
                            CommandLineInterface.o WindowCoordinate.o\
							WindowSize.o StringUtils.o StringConverter.o
	@echo building $(TEST_BIN_DIR)/gameplay.CommandReaderTest.exe
	@gcc -o $(TEST_BIN_DIR)/gameplay.CommandReaderTest.exe\
	    $(TEST_OBJ_DIR)/CommandReaderTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
		$(MAIN_OBJ_DIR)/CommandReader.o $(MAIN_OBJ_DIR)/CommandLineInterface.o\
		$(MAIN_OBJ_DIR)/WindowCoordinate.o $(MAIN_OBJ_DIR)/WindowSize.o\
		$(MAIN_OBJ_DIR)/StringUtils.o $(MAIN_OBJ_DIR)/StringConverter.o

gameplay.CommandRunnerTest: UnitTest.o CommandRunnerTest.o CommandRunner.o\
                            LevelMap.o WindowCoordinate.o WindowSize.o\
							CommandLineInterface.o StringUtils.o\
							StringConverter.o
	@echo building $(TEST_BIN_DIR)/gameplay.CommandRunnerTest.exe
	@gcc -o $(TEST_BIN_DIR)/gameplay.CommandReaderTest.exe\
	    $(TEST_OBJ_DIR)/CommandRunnerTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
		$(MAIN_OBJ_DIR)/CommandRunner.o $(MAIN_OBJ_DIR)/LevelMap.o\
		$(MAIN_OBJ_DIR)/WindowCoordinate.o $(MAIN_OBJ_DIR)/WindowSize.o\
		$(MAIN_OBJ_DIR)/CommandLineInterface.o $(MAIN_OBJ_DIR)/StringUtils.o\
		$(MAIN_OBJ_DIR)/StringConverter.o

gameplay.LevelMapTest: UnitTest.o LevelMapTest.o StringUtils.o\
                       WindowSize.o WindowCoordinate.o LevelMap.o
	@echo building $(TEST_BIN_DIR)/gameplay.LevelMapTest.exe
	@gcc -o $(TEST_BIN_DIR)/gameplay.LevelMapTest.exe\
	    $(TEST_OBJ_DIR)/LevelMapTest.o $(MAIN_OBJ_DIR)/UnitTest.o\
		$(MAIN_OBJ_DIR)/WindowSize.o $(MAIN_OBJ_DIR)/WindowCoordinate.o\
		$(MAIN_OBJ_DIR)/StringUtils.o $(MAIN_OBJ_DIR)/LevelMap.o

# util
util.StringUtilsTest: UnitTest.o StringUtils.o StringUtilsTest.o
	@echo building $(TEST_BIN_DIR)/util.StringUtilsTest.exe
	@gcc -o $(TEST_BIN_DIR)/util.StringUtilsTest.exe\
	    $(TEST_OBJ_DIR)/StringUtilsTest.o\
	    $(MAIN_OBJ_DIR)/UnitTest.o $(MAIN_OBJ_DIR)/StringUtils.o


# =============================================================================
#                                Source Files
# =============================================================================
config:    CliWindowConfig.o
converter: StringConverter.o
engine:    CommandLineInterface.o WindowCoordinate.o WindowSize.o
gameplay:  CommandReader.o CommandRunner.o LevelMap.o
util:      StringUtils.o

# config
CliWindowConfig.o:
	@echo compiling $(SRC_DIR)/config/CliWindowConfig.c
	@gcc -o $(MAIN_OBJ_DIR)/CliWindowConfig.o\
	     -c $(SRC_DIR)/config/CliWindowConfig.c -Iinclude	

# converter
StringConverter.o:
	@echo compiling $(SRC_DIR)/converter/StringConverter.c
	@gcc -o $(MAIN_OBJ_DIR)/StringConverter.o\
	     -c $(SRC_DIR)/converter/StringConverter.c -Iinclude

# engine
CommandLineInterface.o:
	@echo compiling $(SRC_DIR)/engine/CommandLineInterface.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandLineInterface.o\
	     -c $(SRC_DIR)/engine/CommandLineInterface.c -Iinclude

WindowCoordinate.o:
	@echo compiling $(SRC_DIR)/engine/WindowCoordinate.c
	@gcc -o $(MAIN_OBJ_DIR)/WindowCoordinate.o\
	     -c $(SRC_DIR)/engine/WindowCoordinate.c -Iinclude

WindowSize.o:
	@echo compiling $(SRC_DIR)/engine/WindowSize.c
	@gcc -o $(MAIN_OBJ_DIR)/WindowSize.o\
	     -c $(SRC_DIR)/engine/WindowSize.c -Iinclude

# gameplay
CommandReader.o:
	@echo compiling $(SRC_DIR)/gameplay/CommandReader.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandReader.o\
	     -c $(SRC_DIR)/gameplay/CommandReader.c -Iinclude

CommandRunner.o:
	@echo compiling $(SRC_DIR)/gameplay/CommandRunner.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandRunner.o\
	     -c $(SRC_DIR)/gameplay/CommandRunner.c -Iinclude

LevelMap.o:
	@echo compiling $(SRC_DIR)/gameplay/LevelMap.c
	@gcc -o $(MAIN_OBJ_DIR)/LevelMap.o\
	     -c $(SRC_DIR)/gameplay/LevelMap.c -Iinclude

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
# converter
StringConverterTest.o:
	@echo compiling $(TEST_DIR)/converter/StringConverterTest.c
	@gcc -o $(TEST_OBJ_DIR)/StringConverterTest.o\
	     -c $(TEST_DIR)/converter/StringConverterTest.c -Iinclude

# engine
CommandLineInterfaceManualTest.o:
	@echo compiling $(TEST_DIR)/engine/CommandLineInterfaceManualTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandLineInterfaceManualTest.o\
	     -c $(TEST_DIR)/engine/CommandLineInterfaceManualTest.c -Iinclude

WindowCoordinateTest.o:
	@echo compiling $(TEST_DIR)/engine/WindowCoordinateTest.c
	@gcc -o $(TEST_OBJ_DIR)/WindowCoordinateTest.o\
	     -c $(TEST_DIR)/engine/WindowCoordinateTest.c -Iinclude

WindowSizeTest.o:
	@echo compiling $(TEST_DIR)/engine/WindowSizeTest.c
	@gcc -o $(TEST_OBJ_DIR)/WindowSizeTest.o\
	     -c $(TEST_DIR)/engine/WindowSizeTest.c -Iinclude

# gameplay
CommandReaderTest.o:
	@echo compiling $(TEST_DIR)/gameplay/CommandReaderTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandReaderTest.o\
	     -c $(TEST_DIR)/gameplay/CommandReaderTest.c -Iinclude

CommandRunnerTest.o:
	@echo compiling $(TEST_DIR)/gameplay/CommandRunnerTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandRunnerTest.o\
	     -c $(TEST_DIR)/gameplay/CommandRunnerTest.c -Iinclude

LevelMapTest.o:
	@echo compiling $(TEST_DIR)/gameplay/LevelMapTest.c
	@gcc -o $(TEST_OBJ_DIR)/LevelMapTest.o\
	     -c $(TEST_DIR)/gameplay/LevelMapTest.c -Iinclude

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
check: clean-test build-dir test-auto
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
