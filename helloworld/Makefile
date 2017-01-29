VERBOSE := 1
ifndef (VERBOSE)
  Q:=@
else
  Q:=
endif

PWD := $(shell pwd)
SOURCE_DIR := $(PWD)/src
BUILD_DIR := $(PWD)/build
BUILD_DIR_DEBUG := $(PWD)/build/debug
PATH := $(PATH):/usr/local/bin
GENERATOR := "Unix Makefiles"

all: debug

.PHONY: debug
debug:
	echo $(PWD)
	echo $(SOURCE_DIR)
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	cd "$(BUILD_DIR_DEBUG)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Debug "$(SOURCE_DIR)"
	make -C $(BUILD_DIR_DEBUG) VERBOSE=1
	make -C $(BUILD_DIR_DEBUG) test

.PHONY: release
debug:
	echo $(PWD)
	echo $(SOURCE_DIR)
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	cd "$(BUILD_DIR_DEBUG)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Release "$(SOURCE_DIR)"
	make -C $(BUILD_DIR_DEBUG) VERBOSE=1
	make -C $(BUILD_DIR_DEBUG) test


.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)
