#ifndef WINDOWS_H
#define WINDOWS_H
// Пример не рабочий под линукс. Этот файл - просто заглушка.
enum _Uninitialized {_Noinit};

void OemToChar(const char* ch1, char* ch2);
void CharToOem(const char* ch1, char* ch2);
#endif // WINDOWS_H
