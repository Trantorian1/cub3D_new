# ===============================[ DEPENDENCIES ]============================= #

-include ./build/color.mf
-include ./build/setup.mf

# ==================================[ SETUP ]================================= #

DOCKER = docker run --rm -v .:/app trantorian/criterion:2.4.2.v
CORES  = $(($(nproc) + 1))

all: 
	@echo "$(DIM)$(WHITE)> $(shell date)$(RESET)"
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"
	@make --silent final

clean:
	@echo "$(DIM)$(WHITE)> $(shell date)$(RESET)"
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"
	@make --silent debug_clean
	@make --silent test_clean
	@make --silent final_clean

fclean:
	@echo "$(DIM)$(WHITE)> $(shell date)$(RESET)"
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"
	@make --silent debug_fclean
	@make --silent test_fclean
	@make --silent final_fclean

re:
	@echo "$(DIM)$(WHITE)> $(shell date)$(RESET)"
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"
	@make --silent debug_fclean
	@make --silent test_fclean
	@make --silent final_fclean
	@make --silent final

run: all
	@make --silent --file=./build/build_final.mf run
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

# ==================================[ DEBUG ]================================= #

debug:
	@echo "$(BLUE_BG)$(WHITE)$(BOLD)[ Building ]$(RESET)$(WHITE)$(ITALIC) debug"
	@$(DOCKER) make -j$(CORES) --silent --file=./build/build_debug.mf
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

debug_clean:
	@echo "$(RED_BG)$(WHITE)$(BOLD)[ Cleaning ]$(RESET)$(WHITE)$(ITALIC) debug"
	@make --silent --file=./build/build_debug.mf clean
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

debug_fclean:
	@echo "$(RED_BG)$(WHITE)$(BOLD)[ Cleaning ]$(RESET)$(WHITE)$(ITALIC) debug"
	@make --silent --file=./build/build_debug.mf fclean
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

debug_re: debug_fclean
	@make --sile debug

# ==================================[ TEST ]================================== #

test: debug
	@echo "$(BLUE_BG)$(WHITE)$(BOLD)[ Building ]$(RESET)$(WHITE)$(ITALIC) test"
	@$(DOCKER) make --silent --file=./build/build_test.mf
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

test_clean:
	@echo "$(RED_BG)$(WHITE)$(BOLD)[ Cleaning ]$(RESET)$(WHITE)$(ITALIC) test"
	@make --silent --file=./build/build_test.mf clean
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

test_fclean:
	@echo "$(RED_BG)$(WHITE)$(BOLD)[ Cleaning ]$(RESET)$(WHITE)$(ITALIC) test"
	@make --silent --file=./build/build_test.mf fclean
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

test_re: test_fclean
	@make --silent test

# ==================================[ FINAL ]================================= #

final: test
	@echo "$(BLUE_BG)$(WHITE)$(BOLD)[ Building ]$(RESET)$(WHITE)$(ITALIC) final"
	@make -j$(CORES) --silent --file=./build/build_final.mf
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

final_clean:
	@echo "$(RED_BG)$(WHITE)$(BOLD)[ Cleaning ]$(RESET)$(WHITE)$(ITALIC) final"
	@make --silent --file=./build/build_final.mf clean
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

final_fclean:
	@echo "$(RED_BG)$(WHITE)$(BOLD)[ Cleaning ]$(RESET)$(WHITE)$(ITALIC) final"
	@make --silent --file=./build/build_final.mf fclean
	@echo "$(DIM)$(WHITE)*----------*$(RESET)"

final_re: final_fclean
	@make --silent final



.PHONY: all clean fclean re run                 \
        debug debug_clean debug_fclean debug_re \
		test test_clean test_fclean test_re     \
        final final_clean final_fclean final_re
