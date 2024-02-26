#include "shel_sort.hpp"

int main() {
    int n;
    std::cin >>n;
    std::vector<int> a(n);
    for (int i = 0; i < n;i++){
        std::cin >> a[i];
    }
    ShellSort(n, a);
    for (int i = 0; i < n;i++){
        std::cout<< a[i]<< " ";
    }
}
