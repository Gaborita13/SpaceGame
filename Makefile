CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -MMD -MP
LDFLAGS = -Llib -lraylib
SRC_DIR = src
BUILD_DIR = build

# Sources
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

TARGET = $(BUILD_DIR)/app

all: $(TARGET)

# Génère l'exécutable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile .cpp en .o et génère .d
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

# Inclusion silencieuse des .d (après la 1re compilation)
-include $(DEPS)