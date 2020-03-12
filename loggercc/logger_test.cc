#include "logger.h"
#include <ctime>
#include <thread>
#include <chrono>

int main(){ 
    // Chose file name here (which the constructor calls the Open method).
    loggercc::Logger log("logger.log");

    // Already opened.  
    log.OpenLog("logger.log");
    
    log.WriteLog
    (loggercc::INFO, "in test", __LINE__, __FILE__);
     std::this_thread::sleep_for(std::chrono::seconds(5));  // For checking the time.  Wait 5 seconds.  
    log.WriteLog
    (loggercc::WARNING, "war test", __LINE__, __FILE__);
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    log.WriteLog
    (loggercc::ERROR, "err test", __LINE__, __FILE__);
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    log.WriteLog
    (loggercc::FATAL, "fat test", __LINE__, __FILE__);

    // Can't properly test flush; OS automatically flushes when core is dumped.
    log.Flush();
    // Print Log  to console.
    log.ReadLog("logger.log");

    // The destructor also closes the log.  
    log.CloseLog();
    return 0;
}