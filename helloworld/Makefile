VERBOSE := 1
ifndef (VERBOSE)
  Q:=@
else
  Q:=
endif

PWD := $(shell pwd)
SOURCE_DIR := $(PWD)/src
BUILD_DIR := $(PWD)/build
EXT_DIR := $(PWD)/ext
BUILD_DIR_DEBUG := $(PWD)/build/debug
BUILD_DIR_RELEASE := $(PWD)/build/release
INST_DIR := $(PWD)/inst
INST_DIR_DEBUG := $(INST_DIR)/debug
INST_DIR_RELEASE := $(INST_DIR)/release

PATH := $(PATH):/usr/local/bin
GENERATOR := "Unix Makefiles"

# all: ext debug release
all: debug release

.PHONY: ext
ext:
	echo $(EXT_DIR)
	make -C $(EXT_DIR)

.PHONY: debug
debug:
	$(Q)make -C $(EXT_DIR) debug
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	$(Q)cd "$(BUILD_DIR_DEBUG)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=DEBUG -DINST_DIR="$(INST_DIR_DEBUG)" "$(SOURCE_DIR)"
	$(Q)make -C $(BUILD_DIR_DEBUG) VERBOSE=1
	$(Q)make -C $(BUILD_DIR_DEBUG) test

.PHONY: release
release:
	$(Q)make -C $(EXT_DIR) release
	$(Q)mkdir -p "$(BUILD_DIR_RELEASE)"
	$(Q)cd "$(BUILD_DIR_RELEASE)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=RELEASE -DINST_DIR="$(INST_DIR_RELEASE)" "$(SOURCE_DIR)"
	$(Q)make -C $(BUILD_DIR_RELEASE) VERBOSE=1
	$(Q)make -C $(BUILD_DIR_RELEASE) test

.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)
