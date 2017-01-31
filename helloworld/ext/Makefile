ifndef (VERBOSE)
  Q:=@
else
  Q:=
endif

PWD := $(shell pwd)
BUILD_DIR := $(PWD)/../build/ext
BUILD_DIR_DEBUG := $(BUILD_DIR)/debug
BUILD_DIR_RELEASE := $(BUILD_DIR)/release
GOOGLE_TEST_DIR := $(PWD)/googletest
INST_DIR := $(PWD)/../inst
INST_DIR_DEBUG := $(INST_DIR)/debug
INST_DIR_RELEASE := $(INST_DIR)/release
#PATH := $(PATH):/usr/local/bin
GENERATOR := "Unix Makefiles"

all: debug release

.PHONY: debug
debug:
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	$(Q)mkdir -p "$(INST_DIR_DEBUG)"
	cd "$(BUILD_DIR_DEBUG)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=DEBUG "$(GOOGLE_TEST_DIR)"
	make -C $(BUILD_DIR_DEBUG) VERBOSE=1
	make -C $(BUILD_DIR_DEBUG) DESTDIR=$(INST_DIR_DEBUG) install

.PHONY: release
release:
	$(Q)mkdir -p "$(BUILD_DIR_RELEASE)"
	$(Q)mkdir -p "$(INST_DIR_RELEASE)"
	cd "$(BUILD_DIR_RELEASE)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=RELEASE "$(GOOGLE_TEST_DIR)"
	make -C $(BUILD_DIR_RELEASE) VERBOSE=1
	make -C $(BUILD_DIR_RELEASE) DESTDIR=$(INST_DIR_RELEASE) install

.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)
