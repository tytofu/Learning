// 若内联函数放在头文件中,则头文件中必须包含函数体
// 因为是在编译时进行的函数展开,而不是像普通函数那样在链接阶段
// 进行链接
inline int add(int x, int y = 10) { return x + y; }