.PHONY: clean All

All:
	@echo "----------Building project:[ assignement4 - Debug ]----------"
	@cd "assignement4" && "$(MAKE)" -f  "assignement4.mk"
clean:
	@echo "----------Cleaning project:[ assignement4 - Debug ]----------"
	@cd "assignement4" && "$(MAKE)" -f  "assignement4.mk" clean
