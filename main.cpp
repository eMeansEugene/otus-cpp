#include "lib.h"

#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>

int main(int argc, char* argv[]) {

    std::random_device rd;             
    std::mt19937 gen(rd());             
    std::uniform_real_distribution<double> dist(0.0, 1.0);


	std::cout << "Version: " << version() << std::endl;
	std::cout << "Hello, world!" << std::endl;

		
	if (argc > 1) {
		uint64_t inside = 0;
		try {
			auto experiments = std::stoull(argv[1]);
			if (experiments == 0) {
	 		   std::cerr << "Number of experiments must be > 0\n";
	    		return 1;
			}
			for (uint64_t i = 0; i < experiments; ++i) {
			    double x = dist(gen);
			    double y = dist(gen);
	    		if (x * x + y * y <= 1.0) {
	        		++inside;
				}
			}
			double pi = 4.0 * inside / experiments;
			std::cout << "Estimated PI = " << pi << std::endl;		
		} catch (const std::exception& e) {
		    std::cerr << "Invalid number format\n";
		    return 1;		
		}
	}

	
	return 0;
}
