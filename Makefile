PLATFORM ?= nds

ifeq ($(PLATFORM),nds)
include make/makefile_nds
else ifeq ($(PLATFORM),gba)
include make/makefile_gba
else
	$(error Unknown platform: $(PLATFORM))
endif

clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET).elf $(TARGET).nds $(TARGET).gba $(TARGET).map