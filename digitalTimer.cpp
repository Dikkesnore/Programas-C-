/******************************
 *                            *
 *    Simple clock program    *
 *                            *
 ******************************/

#include <iostream>
#include <iomanip>
#include <ctime>

// Variaveis globais
const clock_t SEC_PER_MIN = 60, SEC_PER_HOUR = 60 * SEC_PER_MIN, SEC_PER_DAY = 24 * SEC_PER_HOUR;

// Prototipos
void print_time(clock_t seconds);

int main()
{
	clock_t start = clock();
	clock_t elapsed = (clock() - start) / CLOCKS_PER_SEC, previousElapsed = elapsed;
	
	// Contar até 24 horas e parar
	while(elapsed < SEC_PER_DAY)
	{
		// Atualizar o relógio a cada 1 segundo
		if (elapsed - previousElapsed >= 1)
		{
			// Lembrar de atualizar o display de onde ele parou
			previousElapsed = elapsed;
			print_time(elapsed);
		}
	// Atualizar o tempo que se passou
	elapsed = (clock() - start) / CLOCKS_PER_SEC;
	}
}

void print_time(clock_t seconds)
{
	clock_t hours = 0, minutes = 0;

	// Preparar o mostruário
	std::cout << "\n";
	std::cout << "     ";

	// Computar e mostrar as horas
	hours = seconds / SEC_PER_HOUR;
	std::cout << std::setw(2) << std::setfill('0') << hours << ":";

	// Remover as horas dos segundos
	seconds %= SEC_PER_HOUR;

	// Computar e mostrar os minutos
	minutes = seconds/SEC_PER_MIN;
	std::cout << std::setw(2) << std::setfill('0') << minutes << ":";

	// Remover os minutos dos segundos
	seconds %= SEC_PER_MIN;

	// Mostrar os segundos
	std::cout << std::setw(2) << std::setfill('0') << seconds << '\n';
}