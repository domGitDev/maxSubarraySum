#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template<typename T>
auto maxSubarraySum(const auto &arr, const auto &size)
{ // Compute max contiguous and non contiguous array sum
    
    if(arr.size() != size && size <= 0)
        throw std::invalid_argument(
            "Vector.size differs from param size");
    
    T contig_sum = arr[0];
    T curr_sum = arr[0];

    T non_contig_sum = arr[0];
    vector<T> temp(2);
    temp[0] = arr[0];

    for(T i=1; i<size; i++){
        curr_sum = max(arr[i], curr_sum + arr[i]);
        contig_sum = max(curr_sum, contig_sum);
        
        temp[1] = max(temp[0], temp[0]+arr[i]);
        non_contig_sum = max(temp[1], arr[i]);
        temp[0] = temp[1];
    }
    
    return std::make_tuple<T, T> (contig_sum, non_contig_sum);
}


template<typename T>
auto readInputToArray(const auto &size)
{
    vector<T> values(size);
    for(T i=0; i<size; i++){
        cin >> values[i];
    }
    return std::move(values);
}


int main() {
    /* Enter your code here. 
    Read input from STDIN. Print output to STDOUT */   
    
    unsigned int q;
    long int size;
    
    cin >> q;

    for(unsigned int i=0; i<q; i++){
        cin >> size;
        const auto &data = readInputToArray<long>(size);
        if(data.size() == size)
            const auto &max_sums = maxSubarraySum<long>(data, size);
            cout<<std::get<0>(max_sums)<<" "<<std::get<1>(max_sums)<<endl;
    }
    return 0;
}

