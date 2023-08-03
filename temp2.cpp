#include <iostream>
#include <Windows.h>

#include <wincrypt.h>
#pragma comment(lib, "Advapi32.lib")
int main() {
    const int bufferSize = 4096; // Adjust buffer size as per your needs
    const int writeSpeed = 100; // Adjust write speed (milliseconds) as per your needs

    const char* filePath = "C:\\Users\\Ojas Sharma\\Desktop\\ds\\binary_trees\\tempp.bin";


    HANDLE fileHandle = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE) {
        std::cout << "Error creating file." << std::endl;
        return 1;
    }

    char* buffer = new char[bufferSize];
    DWORD bytesWritten;

    HCRYPTPROV hCryptProv;
    if (!CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, 0)) {
        std::cout << "Error acquiring cryptographic context." << std::endl;
        CloseHandle(fileHandle);
        return 1;
    }

    while (true) {
        // Generate random data in the buffer
        if (!CryptGenRandom(hCryptProv, bufferSize, reinterpret_cast<BYTE*>(buffer))) {
            std::cout << "Error generating random data." << std::endl;
            break;
        }

        // Write the buffer to the file
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, NULL)) {
            std::cout << "Error writing to file." << std::endl;
            break;
        }

        // Wait for the desired write speed
        Sleep(writeSpeed);
    }

    delete[] buffer;
    CryptReleaseContext(hCryptProv, 0);
    CloseHandle(fileHandle);
    return 0;
}
