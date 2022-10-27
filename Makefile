all: clean autocomplete
autocomplete:
	@echo " "
	@echo "==============================="
	@echo "|         AUTO-COMPLETE       |"
	@echo "==============================="
	@echo "Compilando o auto-complete. Programa autocomplete"
	gcc Autocomplete.h Autocomplete.c main.c -o autocomplete -lm
	chmod +x autocomplete
clean:
	@echo " "
	@echo "==============================="
	@echo "|    REMOVENDO PROGRAMAS      |"
	@echo "==============================="
	@echo "Removendo os arquivos compilados"
	rm -f autocomplete