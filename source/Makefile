#VERBOSE := 1
ifndef (VERBOSE)
  Q:=@
else
  Q:=
endif

PWD := $(shell pwd)
PROJECT_DIR := $(PWD)/..
SOURCE_DIR := $(PROJECT_DIR)/source
BUILD_DIR := $(PROJECT_DIR)/build
EXT_DIR := $(PROJECT_DIR)/ext
BUILD_DIR_DEBUG := $(BUILD_DIR)/debug
BUILD_DIR_RELEASE := $(BUILD_DIR)/release
PREFIX_DIR := $(PROJECT_DIR)/root/usr/local

PATH := $(PATH):/usr/local/bin
GENERATOR := "Unix Makefiles"

COMMON_CMAKE_FLAGS := -G $(GENERATOR) -DEXT_DIR="$(EXT_DIR)" -DCMAKE_INSTALL_PREFIX=$(PREFIX_DIR)
DEBUG_CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=debug -DCMAKE_DEBUG_POSTFIX=d
RELEASE_CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=release
# all: ext debug release
all: debug release

.PHONY: ext
ext:
	echo $(EXT_DIR)
	make -C $(EXT_DIR)

.PHONY: debug
debug: $(BUILD_DIR_DEBUG)/Makefile
	$(Q)make -C $(BUILD_DIR_DEBUG) 
	$(Q)make -C $(BUILD_DIR_DEBUG) test

$(BUILD_DIR_DEBUG)/Makefile:
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	$(Q)cd "$(BUILD_DIR_DEBUG)" && cmake $(COMMON_CMAKE_FLAGS) $(DEBUG_CMAKE_FLAGS) "$(SOURCE_DIR)"

.PHONY: release
release: $(BUILD_DIR_RELEASE)/Makefile
	$(Q)make -C $(BUILD_DIR_RELEASE) VERBOSE=1
	$(Q)make -C $(BUILD_DIR_RELEASE) test

$(BUILD_DIR_RELEASE)/Makefile:
	$(Q)mkdir -p "$(BUILD_DIR_RELEASE)"
	$(Q)cd "$(BUILD_DIR_RELEASE)" && cmake $(COMMON_CMAKE_FLAGS) $(RELEASE_CMAKE_FLAGS) "$(SOURCE_DIR)"

.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)
