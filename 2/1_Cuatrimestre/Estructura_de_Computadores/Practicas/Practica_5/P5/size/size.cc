// size.cc

#include <array>        // array
#include <chrono>       // high_resolution_clock
#include <iomanip>      // setw
#include <iostream>     // cout

using namespace std::chrono;

const unsigned MINSIZE = 1 << 10; // maximun cache size to test:  1KB
const unsigned MAXSIZE = 1 << 24; // maximun cache size to test: 16MB
const unsigned GAP = 12;          // gap for cout columns
const unsigned REP = 100;         // number of repetitions of every test
const unsigned STEPS = 1e7;       // 10M steps

std::array<char, MAXSIZE> bytes;

int main()
{
	std::cout << "#" 
	          << std::setw(GAP - 1) << "size (B)"
	          << std::setw(GAP    ) << "time (ms)"
	          << std::endl;

	bytes.fill(0);

	for (unsigned size = MINSIZE; size <= MAXSIZE; size *= 2)
	{
		std::array<duration<float, std::milli>, REP> score;

		for (auto &s: score)
		{
			auto start = high_resolution_clock::now();

			for (unsigned i = 0; i < STEPS; ++i)
				bytes[(i*64)&(size-1)] ^=1;

			auto stop = high_resolution_clock::now();

			s = stop - start;
		}

		std::cout << std::setw(GAP) << size
		          << std::setw(GAP) << std::fixed << std::setprecision(1)
		          << std::setw(GAP) << std::min(score.begin(), score.end())->count()
		          << std::endl;
	}

	return bytes.front() + bytes.back();
}
