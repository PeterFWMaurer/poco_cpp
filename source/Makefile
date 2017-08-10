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
INST_DIR := $(PROJECT_DIR)/inst
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
debug: $(BUILD_DIR_DEBUG)/Makefile
	$(Q)make -C $(BUILD_DIR_DEBUG) 
	$(Q)make -C $(BUILD_DIR_DEBUG) test

$(BUILD_DIR_DEBUG)/Makefile:
	$(Q)mkdir -p "$(BUILD_DIR_DEBUG)"
	$(Q)cd "$(BUILD_DIR_DEBUG)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=DEBUG -DINST_DIR="$(INST_DIR_DEBUG)" "$(SOURCE_DIR)"

.PHONY: release
release: $(BUILD_DIR_RELEASE)/Makefile
#	$(Q)make -C $(EXT_DIR) release
#	$(Q)mkdir -p "$(BUILD_DIR_RELEASE)"
#	$(Q)cd "$(BUILD_DIR_RELEASE)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=RELEASE -DINST_DIR="$(INST_DIR_RELEASE)" "$(SOURCE_DIR)"
	$(Q)make -C $(BUILD_DIR_RELEASE) VERBOSE=1
	$(Q)make -C $(BUILD_DIR_RELEASE) test

$(BUILD_DIR_RELEASE)/Makefile:
	$(Q)mkdir -p "$(BUILD_DIR_RELEASE)"
	$(Q)cd "$(BUILD_DIR_RELEASE)" && cmake -G $(GENERATOR) -DCMAKE_BUILD_TYPE=RELEASE -DINST_DIR="$(INST_DIR_RELEASE)" "$(SOURCE_DIR)"

.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)
