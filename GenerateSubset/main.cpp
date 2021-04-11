#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum call{GENERATE_SUBSETS, SUBSET};

struct SubsetCall{
    int type;
    int i, j;
};

void GenerateSubsetsUtil(int *a, int n, int *subsets){
    SubsetCall call_1;
    call_1.type = GENERATE_SUBSETS;
    call_1.i = 0;
    call_1.j = 0;

    stack<SubsetCall> stackk;
    //add first call to the stack then start the loop that simulate recursion
    stackk.push(call_1);

    while(!stackk.empty()){
        SubsetCall call = stackk.top(); stackk.pop();

        if (call.type == SUBSET){
            subsets[call.j] = a[call.i];
            continue;
        }

        if (call.i == n){
            for (int i=0 ; i < call.j ; i++)
                cout<<subsets[i]<<' ';
            cout<<endl;
            continue;
        }

        SubsetCall c1;
        c1.type=GENERATE_SUBSETS;
        c1.i = call.i + 1;
        c1.j = call.j;

        SubsetCall c2;
        c2.type = SUBSET;
        c2.j = call.j;
        c2.i = call.i;

        SubsetCall c3;
        c3.type = GENERATE_SUBSETS;
        c3.i = call.i + 1;
        c3.j = call.j+1;

        stackk.push(c3);
        stackk.push(c2);
        stackk.push(c1);
    }
}

void GenerateSubsets(int *a, int n){
    int subsets[1000];
    GenerateSubsetsUtil(a, n, subsets);
}

int main()
{
   int a[]={1,3, 2}; int n=sizeof(a)/sizeof(a[0]);

    GenerateSubsets(a, n); // Prints (in any order): {} {1} {3} {8} {1,3} {1,8} {3,8} {1,3,8}
                           // For example, the following order is also ok: {} {1} {1,3} {1,3,8} {1,8} {3} {3,8} {8}
    return 0;
}
