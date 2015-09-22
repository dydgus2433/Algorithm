#ifndef __METRO__
#define __METRO__

#include <string>
#include "Subway.h"

class Metro{
	private:
		Subway** subway;
		int lines;
	public:
		Metro(int argc, char** argv);
		~Metro();
		/*
		 * findPath: (line)호선에서 first역과 second역이 있는지 검사한다.
		 * printPath: (line)호선에서 first와 second사이의 역을 모두 출력.
		 */
		bool findPath(int line, std::string first, std::string second);
		void printPath(int line, std::string first, std::string second);
};

#endif
