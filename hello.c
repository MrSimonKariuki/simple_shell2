#include <unistd.h>

int main() {
    const char message[] = "Hello shell\n";
    write(STDOUT_FILENO, message, sizeof(message) - 1); 
    return 0; 
}
