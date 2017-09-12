VERBOSE := 1
ifndef (VERBOSE)
  Q:=@
else
  Q:=
endif

PWD := $(shell pwd)
PROJECT_DIR := $(PWD)/..
SOURCE_DIR := $(PROJECT_DIR)/source
BUILD_DIR := $(PWD)/build
EXT_DIR := $(PROJECT_DIR)/ext
EXT_DIR_DEBUG := $(EXT_DIR)/build/debug
EXT_DIR_RELEASE := $(EXT_DIR)/build/release
BUILD_DIR_DEBUG := $(BUILD_DIR)/debug
BUILD_DIR_RELEASE := $(BUILD_DIR)/release
PREFIX_ROOT := $(PROJECT_DIR)/root
PREFIX_DIR := $(PREFIX_ROOT)/usr/local

PATH := $(PATH):/usr/local/bin
GENERATOR := "Unix Makefiles"

COMMON_CMAKE_FLAGS := -G $(GENERATOR) -DEXT_DIR="$(EXT_DIR)" -DCMAKE_INSTALL_PREFIX=$(PREFIX_DIR)
DEBUG_CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_DEBUG_POSTFIX=d
FULL_DEBUG_CMAKE_FLAGS := $(DEBUG_CMAKE_FLAGS) -DBUILD_EXT_PROJECTS=1
RELEASE_CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=RELEASE

#
# all: makes all parts of the project, the right thing to be used everyday in eclipse
#
.PHONY: all
all: debug release

#
# full: makes everything including external projects
#
.PHONY: full
full: ext_debug ext_release all

.PHONY: full_debug
full_debug: ext_debug debug

.PHONY: full_release
full_release: ext_release release

.PHONY: ext_debug
ext_debug:
	$(Q)mkdir -p "$(EXT_DIR_DEBUG)" 
	$(Q)cd "$(EXT_DIR_DEBUG)" && cmake $(COMMON_CMAKE_FLAGS) $(DEBUG_CMAKE_FLAGS) "$(EXT_DIR)"
	$(Q)make -C "$(EXT_DIR_DEBUG)"
	
.PHONY: ext_release
ext_release:
	$(Q)mkdir -p "$(EXT_DIR_RELEASE)" 
	$(Q)cd "$(EXT_DIR_RELEASE)" && cmake $(COMMON_CMAKE_FLAGS) $(RELEASE_CMAKE_FLAGS) "$(EXT_DIR)"
	$(Q)make -C "$(EXT_DIR_RELEASE)"

.PHONY: debug
debug:
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	$(Q)cd "$(BUILD_DIR_DEBUG)" && cmake $(COMMON_CMAKE_FLAGS) $(DEBUG_CMAKE_FLAGS) "$(SOURCE_DIR)"
	$(Q)make -C $(BUILD_DIR_DEBUG) 
#	$(Q)make -C $(BUILD_DIR_DEBUG) test

.PHONY: release
release: 
	$(Q)mkdir -p "$(BUILD_DIR_RELEASE)"
	$(Q)cd "$(BUILD_DIR_RELEASE)" && cmake $(COMMON_CMAKE_FLAGS) $(RELEASE_CMAKE_FLAGS) "$(SOURCE_DIR)"
	$(Q)make -C $(BUILD_DIR_RELEASE) VERBOSE=1
#	$(Q)make -C $(BUILD_DIR_RELEASE) test


.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)

.PHONY: ext_clean	
ext_clean:
	$(Q)rm -rf "$(EXT_DIR)/build"

.PHONY: clean_all
clean_all: clean ext_clean
	$(Q)rm -rf $(PREFIX_ROOT)
