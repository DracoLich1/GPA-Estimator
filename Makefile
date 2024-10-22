# Compiler
CPP = g++

# Directories
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
INCLUDE = $(SRC_DIR)/include

# Phony targets
.PHONY: all always run target clean

# Target
target: $(BUILD_DIR)/GPAEstimater.exe
$(BUILD_DIR)/GPAEstimator.exe: all always
	


# Running the executable
run:
	./build/GPAEstimater.exe

# Directories that must always exist during make
always:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
