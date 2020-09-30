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
MAIN_SRC_DIR = src/main/c
TEST_SRC_DIR = src/test/c

HEADERS_DIR = src/main/headers

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
	@gcc -o $(MAIN_BIN_DIR)/snake-cli.exe $(MAIN_SRC_DIR)/SnakeCliApplication.c\
	    $(MAIN_OBJ_DIR)/*.o -I$(HEADERS_DIR)


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
converter.StringConverterTest: StringConverterTest.o
	@echo building $(TEST_BIN_DIR)/converter.StringConverterTest.exe
	@gcc -o $(TEST_BIN_DIR)/converter.StringConverterTest.exe\
	    $(TEST_OBJ_DIR)/StringConverterTest.o $(MAIN_OBJ_DIR)/*.o

# engine
engine.CommandLineInterfaceManualTest: CommandLineInterfaceManualTest.o
	@echo building $(TEST_BIN_DIR)/engine.CommandLineInterfaceManualTest.exe
	@gcc -o $(TEST_BIN_DIR)/engine.CommandLineInterfaceManualTest.exe\
	    $(TEST_OBJ_DIR)/CommandLineInterfaceManualTest.o $(MAIN_OBJ_DIR)/*.o

engine.WindowCoordinateTest: WindowCoordinateTest.o
	@echo building $(TEST_BIN_DIR)/engine.WindowCoordinateTest.exe
	@gcc -o $(TEST_BIN_DIR)/engine.WindowCoordinateTest.exe\
	    $(TEST_OBJ_DIR)/WindowCoordinateTest.o $(MAIN_OBJ_DIR)/*.o

engine.WindowSizeTest: WindowSizeTest.o
	@echo building $(TEST_BIN_DIR)/engine.WindowSizeTest.exe
	@gcc -o $(TEST_BIN_DIR)/engine.WindowSizeTest.exe\
	    $(TEST_OBJ_DIR)/WindowSizeTest.o $(MAIN_OBJ_DIR)/*.o

# gameplay
gameplay.CommandReaderTest: CommandReaderTest.o
	@echo building $(TEST_BIN_DIR)/gameplay.CommandReaderTest.exe
	@gcc -o $(TEST_BIN_DIR)/gameplay.CommandReaderTest.exe\
	    $(TEST_OBJ_DIR)/CommandReaderTest.o $(MAIN_OBJ_DIR)/*.o

gameplay.CommandRunnerTest: CommandRunnerTest.o
	@echo building $(TEST_BIN_DIR)/gameplay.CommandRunnerTest.exe
	@gcc -o $(TEST_BIN_DIR)/gameplay.CommandRunnerTest.exe\
	    $(TEST_OBJ_DIR)/CommandRunnerTest.o $(MAIN_OBJ_DIR)/*.o

gameplay.LevelMapTest: LevelMapTest.o
	@echo building $(TEST_BIN_DIR)/gameplay.LevelMapTest.exe
	@gcc -o $(TEST_BIN_DIR)/gameplay.LevelMapTest.exe\
	    $(TEST_OBJ_DIR)/LevelMapTest.o $(MAIN_OBJ_DIR)/*.o

# util
util.StringUtilsTest: StringUtilsTest.o
	@echo building $(TEST_BIN_DIR)/util.StringUtilsTest.exe
	@gcc -o $(TEST_BIN_DIR)/util.StringUtilsTest.exe\
	    $(TEST_OBJ_DIR)/StringUtilsTest.o $(MAIN_OBJ_DIR)/*.o


# =============================================================================
#                                Source Files
# =============================================================================
config:    CliWindowConfig.o
converter: StringConverter.o
engine:    CommandLineInterface.o WindowCoordinate.o WindowSize.o
gameplay:  CommandReader.o CommandRunner.o LevelMap.o
util:      StringUtils.o

# config
CliWindowConfig.o: CommandLineInterface.o
	@echo compiling $(MAIN_SRC_DIR)/config/CliWindowConfig.c
	@gcc -o $(MAIN_OBJ_DIR)/CliWindowConfig.o\
	     -c $(MAIN_SRC_DIR)/config/CliWindowConfig.c -I$(HEADERS_DIR)

# converter
StringConverter.o: StringUtils.o
	@echo compiling $(MAIN_SRC_DIR)/converter/StringConverter.c
	@gcc -o $(MAIN_OBJ_DIR)/StringConverter.o\
	     -c $(MAIN_SRC_DIR)/converter/StringConverter.c -I$(HEADERS_DIR)

# engine
CommandLineInterface.o: StringConverter.o StringUtils.o
	@echo compiling $(MAIN_SRC_DIR)/engine/CommandLineInterface.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandLineInterface.o\
	     -c $(MAIN_SRC_DIR)/engine/CommandLineInterface.c -I$(HEADERS_DIR)

WindowCoordinate.o: WindowSize.o
	@echo compiling $(MAIN_SRC_DIR)/engine/WindowCoordinate.c
	@gcc -o $(MAIN_OBJ_DIR)/WindowCoordinate.o\
	     -c $(MAIN_SRC_DIR)/engine/WindowCoordinate.c -I$(HEADERS_DIR)

WindowSize.o:
	@echo compiling $(MAIN_SRC_DIR)/engine/WindowSize.c
	@gcc -o $(MAIN_OBJ_DIR)/WindowSize.o\
	     -c $(MAIN_SRC_DIR)/engine/WindowSize.c -I$(HEADERS_DIR)

# gameplay
CommandReader.o: CommandLineInterface.o
	@echo compiling $(MAIN_SRC_DIR)/gameplay/CommandReader.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandReader.o\
	     -c $(MAIN_SRC_DIR)/gameplay/CommandReader.c -I$(HEADERS_DIR)

CommandRunner.o: CommandLineInterface.o LevelMap.o
	@echo compiling $(MAIN_SRC_DIR)/gameplay/CommandRunner.c
	@gcc -o $(MAIN_OBJ_DIR)/CommandRunner.o\
	     -c $(MAIN_SRC_DIR)/gameplay/CommandRunner.c -I$(HEADERS_DIR)

LevelMap.o: StringUtils.o
	@echo compiling $(MAIN_SRC_DIR)/gameplay/LevelMap.c
	@gcc -o $(MAIN_OBJ_DIR)/LevelMap.o\
	     -c $(MAIN_SRC_DIR)/gameplay/LevelMap.c -I$(HEADERS_DIR)

# util
StringUtils.o:
	@echo compiling $(MAIN_SRC_DIR)/util/StringUtils.c
	@gcc -o $(MAIN_OBJ_DIR)/StringUtils.o\
	     -c $(MAIN_SRC_DIR)/util/StringUtils.c -I$(HEADERS_DIR)

UnitTest.o:
	@echo compiling $(MAIN_SRC_DIR)/util/UnitTest.c
	@gcc -o $(MAIN_OBJ_DIR)/UnitTest.o -c $(MAIN_SRC_DIR)/util/UnitTest.c\
	     -I$(HEADERS_DIR)


# =============================================================================
#                                 Test Files
# =============================================================================
# converter
StringConverterTest.o: StringConverter.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/converter/StringConverterTest.c
	@gcc -o $(TEST_OBJ_DIR)/StringConverterTest.o\
	     -c $(TEST_SRC_DIR)/converter/StringConverterTest.c -I$(HEADERS_DIR)

# engine
CommandLineInterfaceManualTest.o: CommandLineInterface.o
	@echo compiling $(TEST_SRC_DIR)/engine/CommandLineInterfaceManualTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandLineInterfaceManualTest.o\
	     -c $(TEST_SRC_DIR)/engine/CommandLineInterfaceManualTest.c\
		 -I$(HEADERS_DIR)

WindowCoordinateTest.o: WindowCoordinate.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/engine/WindowCoordinateTest.c
	@gcc -o $(TEST_OBJ_DIR)/WindowCoordinateTest.o\
	     -c $(TEST_SRC_DIR)/engine/WindowCoordinateTest.c -I$(HEADERS_DIR)

WindowSizeTest.o: WindowSize.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/engine/WindowSizeTest.c
	@gcc -o $(TEST_OBJ_DIR)/WindowSizeTest.o\
	     -c $(TEST_SRC_DIR)/engine/WindowSizeTest.c -I$(HEADERS_DIR)

# gameplay
CommandReaderTest.o: CommandReader.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/gameplay/CommandReaderTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandReaderTest.o\
	     -c $(TEST_SRC_DIR)/gameplay/CommandReaderTest.c -I$(HEADERS_DIR)

CommandRunnerTest.o: CommandRunner.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/gameplay/CommandRunnerTest.c
	@gcc -o $(TEST_OBJ_DIR)/CommandRunnerTest.o\
	     -c $(TEST_SRC_DIR)/gameplay/CommandRunnerTest.c -I$(HEADERS_DIR)

LevelMapTest.o: WindowSize.o LevelMap.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/gameplay/LevelMapTest.c
	@gcc -o $(TEST_OBJ_DIR)/LevelMapTest.o\
	     -c $(TEST_SRC_DIR)/gameplay/LevelMapTest.c -I$(HEADERS_DIR)

# util
StringUtilsTest.o: StringUtils.o UnitTest.o
	@echo compiling $(TEST_SRC_DIR)/util/StringUtilsTest.c
	@gcc -o $(TEST_OBJ_DIR)/StringUtilsTest.o\
	     -c $(TEST_SRC_DIR)/util/StringUtilsTest.c -I$(HEADERS_DIR)


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
