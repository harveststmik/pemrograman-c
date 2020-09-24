.PHONY: clean All

All:
	@echo "----------Building project:[ Pointer1 - Debug ]----------"
	@cd "Pointer1" && "$(MAKE)" -f  "Pointer1.mk"
clean:
	@echo "----------Cleaning project:[ Pointer1 - Debug ]----------"
	@cd "Pointer1" && "$(MAKE)" -f  "Pointer1.mk" clean
