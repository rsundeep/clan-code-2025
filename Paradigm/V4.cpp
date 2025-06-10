#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

// Generic search function using a strategy
std::vector<std::string> searchNames(
    const std::vector<std::string>& names,
    std::function<bool(const std::string&)> searchStrategy)
{
    std::vector<std::string> result;
    for (const auto& name : names) {
        if (searchStrategy(name)) {
            result.push_back(name);
        }
    }
    return result;
}

// Print the result
void printNames(const std::vector<std::string>& names) {
    for (const auto& name : names) {
        printf("%s\n", name.c_str());
    }
}

std::function<bool(const std::string&)> checkStringStrtsWithGivenChar(const char startChar){
    auto startsWithFn = [startChar](const std::string& name) {
            return !name.empty() && std::tolower(name[0]) == std::tolower(startChar);
    };
}


int main() {
    std::vector<std::string> names = {"Sam", "John", "Sara", "Michael", "Steve", "Alice", "susan", "Tom", "Travis"};

    // Closure: Search names starting with a given character
    char startChar = 's';
    auto startsWith = checkStringStrtsWithGivenChar(startChar);

    // Execute and print
    auto filteredStart = searchNames(names, startsWith);
    printf("Names starting with '%c':\n", startChar);
    printNames(filteredStart);

   auto filteredSubstring = searchNames(names,checkStringStrtsWithGivenChar('M'));
    printf("Names starting with '%c':\n", 'M');
    printNames(filteredSubstring);

    return 0;
}
