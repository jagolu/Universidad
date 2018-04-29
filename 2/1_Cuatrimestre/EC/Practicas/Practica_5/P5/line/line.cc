// line.cc

#include <array>        // array
#include <chrono>       // high_resolution_clock
#include <iomanip>      // setw
#include <iostream>     // cout

using namespace std::chrono;

const unsigned MAXLINE = 1024;  // maximun line size to test: 1KB
const unsigned GAP = 12;        // gap for cout columns
const unsigned REP = 100;       // number of repetitions of every test

std::array<char, 1 << 24> bytes; // 16MB

int main()
{
	std::cout << "#" 
	          << std::setw(GAP - 1) << "line (B)"
	          << std::setw(GAP    ) << "time (ms)"
	          << std::endl;

	bytes.fill(0);

	for (unsigned line = 1; line <= MAXLINE; line *= 2) // line in bytes
	{
		std::array<duration<float, std::milli>, REP> score;

		for (auto &s: score)
		{
			auto start = high_resolution_clock::now();

			for (unsigned i = 0; i < bytes.size(); i += line){
				//bytes[(i*line)&(bytes.size()−1)] ^=1;
				bytes[(i)&(bytes.size()-1)] ^=1;
			}

			auto stop = high_resolution_clock::now();

			s = stop - start;
		}

		std::cout << std::setw(GAP) << line
		          << std::setw(GAP) << std::fixed << std::setprecision(1)
		          << std::setw(GAP) << std::min(score.begin(), score.end())->count()
		          << std::endl;
	}

	return bytes.front() + bytes.back();
}

