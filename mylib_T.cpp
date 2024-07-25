template<typename T>
void output_and_clear_list(std::list<T>& list_of_T) {
    for (auto it = list_of_T.begin(); it != list_of_T.end(); ++it) {
        std::cout << *it << std::endl;
    }
    list_of_T.clear();
}