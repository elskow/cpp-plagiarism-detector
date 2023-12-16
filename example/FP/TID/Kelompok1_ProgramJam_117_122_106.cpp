#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <conio.h>

using namespace std;

struct LapInfo
{
    int lap;
    int jam;
    int menit;
    int detik;
};

int jam = 0, menit = 0, detik = 0;
bool running = false;
bool timerRunning = false;
int timerTarget;
vector<LapInfo> laps;

tm getLocalTime()
{
    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    return *localtime(&currentTime);
}
void jamDigital()
{
    cout << "\nTekan 'Q' untuk menghentikan Jam\n" << endl;
    while (true)
    {
        tm currentTime = getLocalTime();

        cout << setfill('0') << setw(2) << currentTime.tm_hour << ":"
             << setw(2) << currentTime.tm_min << ":"
             << setw(2) << currentTime.tm_sec << "\r";

        cout.flush();

        this_thread::sleep_for(chrono::seconds(1));

        if (_kbhit())
        {
            char input = _getch();
            if (input == 'q' || input == 'Q')
            {
                cout << "Jam dihentikan oleh Pengguna\n"
                     << endl;
                break;
            }
        }
    }
}
void printTime()
{
    system("CLS");
    cout << "Stopwatch dimulai\n" << endl;
    cout << jam << ":" << menit << ":" << detik << endl;
    cout << "\nTekan 'Q' untuk menghentikan Stopwatch" << endl;
    cout << "Tekan 'P' untuk menjeda Stopwatch" << endl;
    cout << "Tekan 'R' untuk mereset Stopwatch" << endl;
    cout << "Tekan 'L' untuk memberi lap\n" << endl;
}

void startStopwatch()
{
    char input;
    int lap = 1;

    if (!running)
    {
        running = true;

        while (running)
        {
            for (jam; jam < 24; jam++)
            {
                for (menit; menit < 60; menit++)
                {
                    for (detik; detik < 60; detik++)
                    {
                        printTime();

                        this_thread::sleep_for(chrono::milliseconds(1000));

                        if (_kbhit())
                        {
                            input = _getch();
                            if (input == 'q' || input == 'Q')
                            {
                                running = false;
                                cout << "Stopwatch dihentikan oleh pengguna" << endl;
                                break;
                            }
                            else if (input == 'p' || input == 'P')
                            {
                                running = false;
                                cout << "Stopwatch di jeda. Tekan 'P' untuk melanjutkan." << endl;

                                while (true)
                                {
                                    char resumeInput = _getch();
                                    if (resumeInput == 'p' || resumeInput == 'P')
                                    {
                                        running = true;
                                        break;
                                    }
                                }
                            }
                            else if (input == 'r' || input == 'R')
                            {
                                jam = menit = detik = 0;
                                running = false;
                                cout << "Stopwatch direset" << endl;
                                break;
                            }
                            else if (input == 'l' || input == 'L')
                            {
                                laps.push_back({lap, jam, menit, detik});
                                lap++;
                            }
                        }
                    }
                    detik = 0;
                    if (!running)
                        break;
                }
                menit = 0;
                if (!running)
                    break;
            }
            jam = 0;
        }
    }
    else
    {
        if (running)
        {
            running = false;
        }
        cout << "Stopwatch sudah berjalan" << endl;
    }

    for (const auto &lapInfo : laps )
    {
        cout << "Lap ke-" << lapInfo.lap << ": Jam: " << lapInfo.jam << ", Menit: " << lapInfo.menit << ", Detik: " << lapInfo.detik << endl;
    }
}

void startTimer()
{
    char input;

    if (!timerRunning)
    {
        timerRunning = true;
        cout << "---------------------" << endl;

        cout << "Masukkan waktu target dalam detik: ";
        cin >> timerTarget;

        while (timerRunning)
        {
            detik++;
            
            system("CLS");
            cout << "Timer dimulai\n" << endl;
            cout << "Sisa waktu: " << timerTarget - detik << " Detik" << endl;
            cout << "\nTekan 'Q' untuk menghentikan Timer" << endl;
            cout << "Tekan 'P' untuk menjeda Timer" << endl;
            cout << "Tekan 'R' untuk mereset Timer" << endl;
            
            if (detik >= timerTarget)
            {
                timerRunning = false;
                cout << "Timer selesai" << endl;
            }

            this_thread::sleep_for(chrono::milliseconds(1000));

            if (_kbhit())
            {
                input = _getch();
                if (input == 'q' || input == 'Q')
                {
                    timerRunning = false;
                    cout << "Timer dihentikan oleh pengguna" << endl;
                    break;
                }
                else if (input == 'p' || input == 'P')
                {
                    timerRunning = false;
                    cout << "Timer di jeda. Tekan 'P' untuk melanjutkan." << endl;
                    
                    while (true)
                    {
                        char resumeInput = _getch();
                        if (resumeInput == 'p' || resumeInput == 'P')
                        {
                            timerRunning = true;
                            break;
                        }
                    }  
                }
                else if (input == 'r' || input == 'R')
                {
                    jam = menit = detik = 0;
                    timerRunning = false;
                    cout <<"Timer direset"<< endl;
                }
            } 
        }
    }
    else
    {
        cout << "Timer sudah berjalan" << endl;
    }
}

int main()
{
    int pilihan;

    while (true)
    {
        cout << endl;
        cout << "Program Jam Sederhana" << endl;
        cout << "---------------------" << endl;
        cout << "1. Jam Digital" << endl;
        cout << "2. Start Stopwatch" << endl;
        cout << "3. Start Timer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            jamDigital();
            break;
        case 2:
            startStopwatch();
            break;
        case 3:
            startTimer();
            break;
        case 4:
            return 0;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    }
    return 0;
}