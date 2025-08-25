export module add;

#ifdef BUILDING_ADD_DLL
#define ADD_API __declspec(dllexport)
#else
#define ADD_API __declspec(dllimport)
#endif

export
ADD_API int add(int a, int b) {
    return a + b;
}

export ADD_API int sub(int a, int b) {
    return a - b;
}
	