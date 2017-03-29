#include <iostream>
#include <stdlib.h>
#include <map>
#include <queue>

int main()
{
	int size = 0;

	std::cout << "Size of LRU cache " ;
	std::cin >> size;

	std::queue<int> lru_queue;
	std::map<int, int*> hash;

	lru_queue.push(1);
	lru_queue.push(2);
	lru_queue.push(3);

	std::cout << "print all" << lru_queue.front() << "\n";
	lru_queue.pop();
	std::cout << "print all" << lru_queue.front() << "\n";
	std::cout << "print all" << lru_queue.front() << "\n";

	return 0;
}
