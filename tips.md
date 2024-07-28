# Strategy
To reduce runtime in C++:
```cpp
ios_base::sync_with_stdio(false) // disables synchronization between C and C++ standard streams
cin.untie(nullptr) // untie cin and cout
```