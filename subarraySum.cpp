#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template<typename T>
void maxSubarraySum(const auto &arr, const auto &size)
{
    if(arr.size() != size && size <= 0)
        throw std::invalid_argument(
            "Vector.size differs from param size");
    
    T contig_sum = arr[0];
    T curr_sum = arr[0];

    T max_sum = arr[0];
    vector<T> D(2);
    D[0] = arr[0];

    for(T i=1; i<size; i++){
        curr_sum = max(arr[i], curr_sum + arr[i]);
        contig_sum = max(curr_sum, contig_sum);
        
        D[1] = max(D[0], D[0]+arr[i]);
        max_sum = max(D[1], arr[i]);
        D[0] = D[1];
    }
    cout<<contig_sum<<" "<<max_sum<<endl;
}


template<typename T>
vector<T> readInputToArray(const auto &size)
{
    vector<T> values(size);
    for(T i=0; i<size; i++){
        cin >> values[i];
    }
    return std::move(values);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int q;
    long int size;
    
    cin >> q;

    for(unsigned int i=0; i<q; i++){
        cin >> size;
        const auto &data = readInputToArray<long>(size);
        if(data.size() == size)
            maxSubarraySum<long>(data, size);
    }
    return 0;
}
