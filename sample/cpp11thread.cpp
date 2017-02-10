#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
 
std::mutex g_display_mutex;
int i = 0;

void foo()
{
    std::thread::id this_id = std::this_thread::get_id();

	if (1)
	{
		std::lock_guard<std::mutex> lock(g_display_mutex);
		++i;
		std::cout << "[" << i << "]"
			<< "thread " << this_id << " sleeping...\n";
	}
	else{
		g_display_mutex.lock();
		std::cout << "thread " << this_id << " sleeping...\n";
		g_display_mutex.unlock();
	}
	
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
 
int main()
{
	std::cout << "[" << i << "]"
		<< "C++11 Thread Demo Begin ...\n";
	
    std::thread t1(foo);
    std::thread t2(foo);
 
    t1.join();
    t2.join();
	
	{
		std::lock_guard<std::mutex> lock(g_display_mutex);
		++i;
		std::cout << "[" << i << "]"
			<< "Demo End.\n";
	}
}